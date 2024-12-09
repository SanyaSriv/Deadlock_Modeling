import argparse
import json
import itertools
from tabulate import tabulate
import re

INDENT = "    "
NODE_NUMBER = r'n\d+'
FOR_LOOP_BEGIN = "ruleset {}: 0..NumberNodes-1 do\n"
FOR_LOOP_END = "endruleset;\n"
RULE_LINE = \
"""rule "{}"
{}
==>
Begin
{}
endrule;\n"""

FOR_LOOP_BEGIN_SYM = "ruleset {}: NodeIDs do\n"
FOR_LOOP_BEGIN_REQ_SYM = \
"""ruleset {}: NodeIDs do
        ruleset {}: 1..2 do
"""

def read_json(json_file):
    with open(json_file, "r") as f:
        data = json.load(f)
    return data

class MurphiGen:
    def __init__(self, json_file, skeleton_file, output_file):
        self.json_file = json_file
        self.output_file = output_file
        self.skeleton_file = skeleton_file
        # initializing some variables
        self.nodes = 0
        self.buffer_space = 0
        self.router_config = []
        self.topology = None
        self.rule_combinations = []
        self.generated_rules = []
        self.extra_variables = []
        self.extra_arrays = []
        self.init = ""
        self.json_data = None
    
    def decode_json(self):
        data = read_json(self.json_file)
        self.json_data = data
        self.topology = data["topology"]
        self.router_config = data["routers"]
        self.nodes = data["NumberNodes"]
        self.buffer_space = data["BufferSpaces"]
        self.pre_rules = data["rule_pre_cond"]
        self.fire_rule = data["rule_fire"]
        self.rule_names = self.pre_rules.keys()
        init = data["NewInit"]
        # TODO: Doing a very hacky thing, please improve this later on
        for x in init:
            unique_vars = set(re.findall(NODE_NUMBER, x))
            for i in unique_vars:
                self.init += INDENT + "for {}: 0..NumberNodes-1 do\n".format(i)
            self.init += INDENT + x + "\n"
            for i in unique_vars:
                self.init += INDENT + "endfor;"
        
        for i in data["NewVariables"]:
            self.extra_variables.append("  {}: {};".format(i, data["NewVariables"][i]))

        self.extra_arrays = data["NewArrays"]

        print("The following data was obtained from the JSON files:")
        print("Topoogy = ", self.topology)
        print("Routers: ", self.router_config)
        print("Nodes = ", self.nodes)
        print("Buffer space: ", self.buffer_space)

    def combanatorics(self):
        self.combinations = []
        exhaustive_combinations = []
        for r in range(1, self.nodes+1):  # max actions at a time --> number of nodes in the system
            exhaustive_combinations.extend(itertools.combinations_with_replacement(self.rule_names, r))
        
        # A little more sophisticated approach:
        router_allowed_rules = self.json_data["RuleDistribution"]["Router"]
        regular_allowed_rules = self.json_data["RuleDistribution"]["Regular"]
        router_nodes = len(self.router_config)
        regular_nodes = self.nodes - router_nodes
        print("regular nodes = ", regular_nodes)
        router_combinations = []
        general_combinations = []

        for r in range(0, router_nodes+1):  # Nodes of kind 1 can take 0 to 2 actions
            router_combinations.extend(itertools.combinations_with_replacement(router_allowed_rules, r))

        for r in range(0, regular_nodes+1):  # Nodes of kind 2 can take 0 to 2 actions
            general_combinations.extend(itertools.combinations_with_replacement(regular_allowed_rules, r))
        print(router_combinations)
        print(general_combinations)
        all_combinations = []
        for k1 in general_combinations:  # Actions for the two kind 1 nodes
            for k2 in router_combinations:  # Actions for the two kind 2 nodes
                combined = k1 + k2  # Combine actions from kind 1 and kind 2
                if 1 <= len(combined) <= 4:  # Ensure the total number of actions is 1-4
                    all_combinations.append(combined)

        # Remove duplicates and sort combinations by length
        unique_combinations = sorted(
            set(tuple(sorted(c)) for c in all_combinations),
            key=len  # Sort by length
        )
        self.combinations = unique_combinations
        self.find_unique_tuples(exhaustive_combinations, self.combinations)

    def find_unique_tuples(self, list1, list2):
        # Normalize the tuples in both lists by sorting them
        normalized_list1 = {tuple(sorted(t)) for t in list1}
        normalized_list2 = {tuple(sorted(t)) for t in list2}

        # Find tuples in list1 but not in list2
        only_in_list1 = normalized_list1 - normalized_list2
        print(len(only_in_list1))
        print("uniqueness - ", only_in_list1)

    def generate_rules_symmetry(self):
        for_loop_dictionary = {}
        for_loop_to_rule_mapping = {}
        for_loop_to_end_loop_mapping = {}
        print(self.fire_rule)
        for i in self.fire_rule:
            match = set(re.findall(NODE_NUMBER, self.fire_rule[i]))
            print(match)
            for_loop_dictionary[i] = match
        for i in self.combinations:
            comb_code = ""
            begin_for_loop = ""
            end_for_loop = ""
            combined_rule_conditions = ""
            rule_name = "Rule --> {}"
            node_count = 1 # begin it at 1, increase it as you go along
            rules = []
            for rul in range(0, len(i)):
                rules.append(i[rul])
            rule_name = rule_name.format(" + ".join(rules))

            rule_condition_list = []
            rule_fire_list = []
            rule_variable_assignments = {}

            indent_var = 0
            for rul in rules:
                rule_node_list = sorted(list(for_loop_dictionary[rul]))
                rule_condition = self.pre_rules[rul]
                rule_fire = self.fire_rule[rul]
                temp_new_var_list = []
                if "Send request" in rul:
                        node_count_2 = node_count + 1
                        begin_for_loop += INDENT*(indent_var) + FOR_LOOP_BEGIN_REQ_SYM.format("n" + str(node_count), "n" + str(node_count_2))
                        rule_condition = rule_condition.replace(rule_node_list[0], "n" + str(node_count))
                        rule_fire = rule_fire.replace(rule_node_list[1], "n" + str(node_count_2)).replace(rule_node_list[0], "n" + str(node_count))
                        temp_new_var_list.append("n" + str(node_count))
                        temp_new_var_list.append("n" + str(node_count_2))
                        indent_var += 2
                        node_count += 2
                else:
                    for x in range(0, len(for_loop_dictionary[rul])):
                        print(for_loop_dictionary)
                        begin_for_loop += INDENT*(indent_var) + FOR_LOOP_BEGIN_SYM.format("n" + str(node_count))
                        rule_condition = rule_condition.replace(rule_node_list[x], "n" + str(node_count))
                        rule_fire = rule_fire.replace(rule_node_list[x], "n" + str(node_count))
                        temp_new_var_list.append("n" + str(node_count))
                        indent_var += 1
                        node_count += 1
    
                if rul in rule_variable_assignments:
                    rule_variable_assignments[rul].append(temp_new_var_list)
                else:
                    rule_variable_assignments[rul] = [temp_new_var_list]
                # make the rule pre condition and rule fire here to prevent over-writing in the next iteration
                rule_condition_list.append(rule_condition)
                rule_fire_list.append(rule_fire)
            
            # adding another condition to make sure the same node does not take multiple steps at a time
            var_not_equal = []
            var_not_equal_rule = []
            for var in rule_variable_assignments:
                for var_lis in rule_variable_assignments[var]:
                    var_not_equal.append(var_lis[0])
            for x1 in range(0, len(var_not_equal)):
                for x2 in range(x1+1, len(var_not_equal)):
                    var_not_equal_rule.append("({} != {})".format(var_not_equal[x1], var_not_equal[x2]))

            combined_rule_conditions = INDENT +  (" & \n" + INDENT).join(rule_condition_list + var_not_equal_rule)
            combined_fire_rules = INDENT + ("\n" + INDENT).join(rule_fire_list)
            
            body = RULE_LINE.format(rule_name, combined_rule_conditions, combined_fire_rules)
            body = "\n".join(INDENT*(indent_var+1) + line for line in body.splitlines() if line != "") + "\n"

            # closing all the rule_set for loops
            for rul in rules:
                for _ in range(0, len(for_loop_dictionary[rul])):
                    end_for_loop += INDENT*(indent_var-1) + FOR_LOOP_END
                    indent_var -= 1
            
            if begin_for_loop in for_loop_to_rule_mapping:
                for_loop_to_rule_mapping[begin_for_loop].append(body)
            else:
                for_loop_to_rule_mapping[begin_for_loop] = [body]
                for_loop_to_end_loop_mapping[begin_for_loop] = end_for_loop
            # # making the final condition
            # comb_code = begin_for_loop + body + end_for_loop
            # self.generated_rules.append(comb_code)
            # printint out the final condition
        
        for i in for_loop_to_rule_mapping:
            comb_code = i + "\n\n".join(for_loop_to_rule_mapping[i]) + for_loop_to_end_loop_mapping[i]
            self.generated_rules.append(comb_code)
            print(comb_code)

    def generate_bi_directional_topology_rules(self):
        # for this one, we would need additional rules with every combination
        # of the directions. 
        # So one ruleset of Send request + send request + send request
        # will have 8 rules
        mapping = {0: "CC", 1: "AC"}
        for_loop_dictionary = {}
        for i in self.pre_rules:
            match = set(re.findall(NODE_NUMBER, self.pre_rules[i]))
            for_loop_dictionary[i] = match
        for i in self.combinations:
            comb_code = ""
            begin_for_loop = ""
            end_for_loop = ""
            combined_rule_conditions = ""
            rule_name = "Rule--> {} + [{}]" # the actions + the configuration
            node_count = 1
            rules = []
            # we will generate code for all the combinations
            possibilities = list(itertools.product([0, 1], repeat=len(i)))
            for possib in possibilities:
                for rul in range(0, len(i)):
                    rules.append(i[rul])
                rule_name = rule_name.format(" + ".join(rules), possib)
                rule_condition_list = []
                rule_fire_list = []
                rule_variable_assignments = {}
                indent_var = 0
                for rul in rules:
                    rule_node_list = sorted(list(for_loop_dictionary[rul]))
                    rule_condition = self.pre_rules[rul]
                    rule_fire = self.fire_rule[rul]
                    temp_new_var_list = []
                    # print(sorted(for_loop_dictionary[rul]))
                    if "Send request" in rul:
                            node_count_2 = node_count + 1
                            begin_for_loop += INDENT*(indent_var) + FOR_LOOP_BEGIN_REQ_SYM.format("n" + str(node_count), "n" + str(node_count_2))
                            rule_condition = rule_condition.replace(rule_node_list[0], "n" + str(node_count))
                            rule_fire = rule_fire.replace(rule_node_list[1], "n" + str(node_count_2)).replace(rule_node_list[0], "n" + str(node_count))
                            rule_fire.format(possib)
                            temp_new_var_list.append("n" + str(node_count))
                            temp_new_var_list.append("n" + str(node_count_2))
                            indent_var += 2
                            node_count += 2
                    else:
                        for x in range(0, len(for_loop_dictionary[rul])):
                            print(for_loop_dictionary)
                            begin_for_loop += INDENT*(indent_var) + FOR_LOOP_BEGIN_SYM.format("n" + str(node_count))
                            rule_condition = rule_condition.replace(rule_node_list[x], "n" + str(node_count))
                            rule_fire = rule_fire.replace(rule_node_list[x], "n" + str(node_count))
                            temp_new_var_list.append("n" + str(node_count))
                            indent_var += 1
                            node_count += 1    

    def generate_rules(self):
        for_loop_dictionary = {}
        for i in self.pre_rules:
            # find the number of for-loops we need by finding the nodes
            match = set(re.findall(NODE_NUMBER, self.pre_rules[i]))
            for_loop_dictionary[i] = match
        # print(for_loop_dictionary)
        # start by generating rules for the single terms
        for i in self.combinations:
            comb_code = ""
            begin_for_loop = ""
            end_for_loop = ""
            combined_rule_conditions = ""
            rule_name = "Rule --> {}"
            node_count = 5 # begin it at 1, increase it as you go along
            rules = []
            for rul in range(0, len(i)):
                rules.append(i[rul])
            # making the rule name
            rule_name = rule_name.format(" + ".join(rules))
            # print(rule_name)
            
            # start by adding all the for loops
            rule_condition_list = []
            rule_fire_list = []
            rule_variable_assignments = {}
            indent_var = 0
            for rul in rules:
                rule_node_list = sorted(list(for_loop_dictionary[rul]))
                rule_condition = self.pre_rules[rul]
                rule_fire = self.fire_rule[rul]
                temp_new_var_list = []
                # print(sorted(for_loop_dictionary[rul]))
                for x in range(0, len(for_loop_dictionary[rul])):
                    begin_for_loop += INDENT*(indent_var) + FOR_LOOP_BEGIN.format("n" + str(node_count))
                    rule_condition = rule_condition.replace(rule_node_list[x], "n" + str(node_count))
                    rule_fire = rule_fire.replace(rule_node_list[x], "n" + str(node_count))
                    temp_new_var_list.append("n" + str(node_count))
                    indent_var += 1
                    node_count += 1
                if rul in rule_variable_assignments:
                    rule_variable_assignments[rul].append(temp_new_var_list)
                else:
                    rule_variable_assignments[rul] = [temp_new_var_list]
                # make the rule pre condition and rule fire here to prevent over-writing in the next iteration
                rule_condition_list.append(rule_condition)
                rule_fire_list.append(rule_fire)
            
            # adding another condition to make sure the same node does not take multiple steps at a time
            var_not_equal = []
            var_not_equal_rule = []
            for var in rule_variable_assignments:
                for var_lis in rule_variable_assignments[var]:
                    var_not_equal.append(var_lis[0])
            for x1 in range(0, len(var_not_equal)):
                for x2 in range(x1+1, len(var_not_equal)):
                    var_not_equal_rule.append("({} != {})".format(var_not_equal[x1], var_not_equal[x2]))

            combined_rule_conditions = INDENT +  (" & \n" + INDENT).join(rule_condition_list + var_not_equal_rule)
            combined_fire_rules = INDENT + ("\n" + INDENT).join(rule_fire_list)
            
            body = RULE_LINE.format(rule_name, combined_rule_conditions, combined_fire_rules)
            body = "\n".join(INDENT*(indent_var+1) + line for line in body.splitlines() if line != "") + "\n"

            # closing all the rule_set for loops
            for rul in rules:
                for _ in range(0, len(for_loop_dictionary[rul])):
                    end_for_loop += INDENT*(indent_var-1) + FOR_LOOP_END
                    indent_var -= 1
            
            # making the final condition
            comb_code = begin_for_loop + body + end_for_loop
            self.generated_rules.append(comb_code)
            # printint out the final condition
            # print(comb_code)

    def write_output_file(self):
        f_out = open(self.output_file, 'w')
        with open(self.skeleton_file, 'r') as f:
            for line in f:
                if "ADD_NUM_NODES" in line:
                    line = line.replace("/*ADD_NUM_NODES*/", str(self.nodes))
                if "ADD_BUFF_SPACE" in line:
                    line = line.replace("/*ADD_BUFF_SPACE*/", str(self.buffer_space))
                if "ADD_RULES_IN_HERE" in line:
                    rules = "\n\n".join(self.generated_rules)
                    line = rules
                if "ADD_MORE_VARIABLES" in line:
                    line = line.replace("/*ADD_MORE_VARIABLES*/", "\n".join(self.extra_variables))
                if "ADD_MORE_ARRAYS" in line:
                    line = line.replace("/*ADD_MORE_ARRAYS*/", "\n".join(self.extra_arrays))
                if "ADD_MORE_INIT" in line:
                    line = line.replace("/*ADD_MORE_INIT*/", self.init)
                f_out.write(line)
        f_out.close()
        # read the skeleton file, and store the data in a list
        # perform replacement operations
        # write back the data into the output file

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--json_file", type=str)
    parser.add_argument("--output_file", type=str)
    parser.add_argument("--skeleton_file", type=str)
    args = parser.parse_args()
    print("Json file recieved:", args.json_file)
    print("Output Murphi file:", args.output_file)
    print("Murphi skeleton file:", args.skeleton_file)

    gen_inst = MurphiGen(args.json_file, args.skeleton_file, args.output_file)
    gen_inst.decode_json()
    gen_inst.combanatorics()
    gen_inst.generate_rules()
    gen_inst.write_output_file()
    # gen_inst.write_output_file()

if __name__ == "__main__":
    main()
