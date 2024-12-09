import re
import matplotlib.pyplot as plt

# Define the regex pattern to match the required lines
pattern = re.compile(r"(\d+) states explored in ([\d\.]+)s, with \d+ rules fired and (\d+) states in the queue.")

# Function to parse the file and extract data
def parse_file(file_path):
    states_explored = []
    time_taken = []
    states_in_queue = []

    with open(file_path, 'r') as file:
        for line in file:
            match = pattern.match(line.strip())
            if match:
                states_explored.append(int(match.group(1)))
                time_taken.append(float(match.group(2)))
                states_in_queue.append(int(match.group(3)))

    return states_explored, time_taken, states_in_queue

# Function to plot the data
def plot_data(states_explored, time_taken, states_in_queue):
    plt.figure()

    # # Plot states explored vs time
    # plt.plot(time_taken, states_explored, label="States Explored", marker='o', linewidth=1)

    # Plot states in queue vs time
    plt.plot(time_taken, states_in_queue, label="States in Queue", marker='x', linewidth=0.4)

    plt.xlabel("Time (seconds)")
    plt.ylabel("States")
    plt.title("States vs Time")
    plt.legend()
    plt.grid(True)
    plt.savefig('output_graph.png', format='png', dpi=300)
    plt.close()  # Close the plot to free up memory

if __name__ == "__main__":
    # Path to the file containing the data
    file_path = "output_bounded_token_oscillation.txt"  # Replace with your file name

    # Parse the file
    states_explored, time_taken, states_in_queue = parse_file(file_path)

    # Check if we have valid data to plot
    if states_explored and time_taken and states_in_queue:
        # Plot the data
        plot_data(states_explored, time_taken, states_in_queue)
    else:
        print("No valid data to plot.")

