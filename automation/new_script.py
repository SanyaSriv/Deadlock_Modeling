import re
import matplotlib.pyplot as plt

# Define the regex pattern to match the required lines
pattern = re.compile(r"(\d+) states explored in ([\d\.]+)s, with \d+ rules fired and (\d+) states in the queue.")

# Function to parse a file and extract data
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

# Function to plot data from two files
def plot_data(file1_data, file2_data, output_file):
    # Unpack data for file 1
    states_explored1, time_taken1, states_in_queue1 = file1_data

    # Unpack data for file 2
    states_explored2, time_taken2, states_in_queue2 = file2_data

    plt.figure(figsize=(12, 6))

    # Plot states in queue for file 1
    plt.plot(time_taken1, states_in_queue1, label="File 1: States in Queue", marker='x', linewidth=0.4)

    # Plot states in queue for file 2
    plt.plot(time_taken2, states_in_queue2, label="File 2: States in Queue", marker='o', linewidth=0.4)

    plt.xlabel("Time (seconds)")
    plt.ylabel("States in Queue")
    plt.title("States in Queue vs Time for Two Files")
    plt.legend()
    plt.grid(True)

    # Save the plot to a file
    plt.savefig(output_file, format='png', dpi=300)
    plt.close()  # Close the plot to free up memory

if __name__ == "__main__":
    # File paths
    file1_path = "poppo"  # Replace with your first file name
    file2_path = "poppo2"  # Replace with your second file name

    # Parse the files
    file1_data = parse_file(file1_path)
    file2_data = parse_file(file2_path)

    # Check if we have valid data to plot
    if file1_data[0] and file2_data[0]:  # Checking if states_explored is non-empty
        # Plot the data
        plot_data(file1_data, file2_data, "poppo.png")
    else:
        print("No valid data to plot for one or both files.")

