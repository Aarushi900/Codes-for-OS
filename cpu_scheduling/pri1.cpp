#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

// Define a process struct to hold process information
struct Process
{
    int pid;
    int priority;
    int burst_time;
    int arrival_time;
    int remaining_time;
};

// Define a function to sort processes by arrival time
bool sort_by_arrival_time(const Process &p1, const Process &p2)
{
    return p1.arrival_time < p2.arrival_time;
}

// Define a function to sort processes by priority
bool sort_by_priority(const Process &p1, const Process &p2)
{
    return p1.priority < p2.priority;
}

// Define the priority scheduling function
pair<double, double> priority_scheduling(vector<Process> &processes)
{
    // Sort the processes by arrival time
    sort(processes.begin(), processes.end(), sort_by_arrival_time);

    // Initialize the waiting time and turnaround time
    vector<int> waiting_time(processes.size(), 0);
    vector<int> turnaround_time(processes.size(), 0);

    // Initialize the remaining time for each process
    for (auto &p : processes)
    {
        p.remaining_time = p.burst_time;
    }

    // Initialize the priority queue for the ready processes
    auto ready_queue = priority_queue<Process, vector<Process>, decltype(&sort_by_priority)>(sort_by_priority);

    // Initialize the current time and the index of the next process to arrive
    int current_time = 0;
    int next_arrival_index = 0;

    // Loop until all processes have completed
    while (!ready_queue.empty() || next_arrival_index < processes.size())
    {
        // Add any arriving processes to the ready queue
        while (next_arrival_index < processes.size() && processes[next_arrival_index].arrival_time <= current_time)
        {
            ready_queue.push(processes[next_arrival_index]);
            next_arrival_index++;
        }

        // If the ready queue is empty, wait for the next process to arrive
        if (ready_queue.empty())
        {
            current_time = processes[next_arrival_index].arrival_time;
            continue;
        }

        // Get the highest priority process from the ready queue
        auto current_process = ready_queue.top();
        ready_queue.pop();

        // Calculate the waiting time and turnaround time for the selected process
        waiting_time[current_process.pid - 1] += current_time - current_process.arrival_time;
        turnaround_time[current_process.pid - 1] += current_time - current_process.arrival_time + current_process.burst_time;

        // Update the current time and the remaining time for the selected process
        int time_slice = min(current_process.remaining_time, 1);
        current_time += time_slice;
        current_process.remaining_time -= time_slice;

        // Add the selected process back to the ready queue if it still has remaining time
        if (current_process.remaining_time > 0)
        {
            ready_queue.push(current_process);
        }
    }

    // Calculate the average waiting time and turnaround time
    double avg_waiting_time = accumulate(waiting_time.begin(), waiting_time.end(), 0.0) / processes.size();
    double avg_turnaround_time = accumulate(turnaround_time.begin(), turnaround_time.end(), 0.0) / processes.size();

    // Return the average waiting time and turnaround time
    return make_pair(avg_waiting_time, avg_turnaround_time);
}

int main()
{
    // Example usage
    vector<Process> processes = {
        {1, 3, 10, 0},
        {2, 1, 5, 2},
        {3, 4, 8, 3},
        {4, 2, 4, 5},
    };

    auto [avg_waiting_time, avg_turnaround_time] = priority_scheduling(processes);

    cout << "Average waiting time: " << avg_waiting_time << endl;
    cout << "Average turnaround time: " << avg_turnaround_time << endl;

    return 0;
}
