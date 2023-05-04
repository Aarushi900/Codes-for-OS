#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};
int main()
{
    Process p[5];

    int burst_remaining[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].arrival_time;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].burst_time;
        burst_remaining[i] = p[i].burst_time;
        cout << "Enter priority of the process " << i + 1 << ": ";
        cin >> p[i].priority;
        p[i].id = i + 1;
        cout << endl;
    }
    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while (completed != 5)
    {
        int mp = -1;
        int idx = -1;
        for (int i = 0; i < 5; i++)
        {
            if (p[i].arrival_time <= current_time && burst_remaining[i] != 0)
            {
                if (p[i].priority < mp)
                {
                    mp = p[i].priority;
                    idx = i;
                }
            }
        }
        if (idx != -1)
        {
            current_time++;
            burst_remaining[idx]--;
            if (burst_remaining[idx] == 0)
            {
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }

    cout << "#P\t"
         << "AT\t"
         << "BT\t"
         << "PRI\t"
         << "WT\t"
         << "TAT\t"
         << "\n"
         << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << p[i].id << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << "\t" << p[i].priority << "\t" << p[i].waiting_time << "\t" << p[i].turnaround_time << "\n"
             << endl;
    }
}