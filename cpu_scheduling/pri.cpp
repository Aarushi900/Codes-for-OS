#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct Process
{
    int id;
    int arr_time;
    int burst_time;
    int wait_time;
    int priority;
    int remaining_time;
};
bool cmp(Process p1, Process p2)
{
    if (p1.arr_time != p2.arr_time)
    {
        return p1.arr_time < p2.arr_time;
    }
    else
    {
        return p1.priority < p2.priority;
    }
}
int main()
{
    Process p[5];
    for (int i = 0; i < 5; i++)
    {
        p[i].id = i + 1;
        cin >> p[i].arr_time >> p[i].burst_time >> p[i].priority;
        p[i].remaining_time = p[i].burst_time;
    }
    sort(p, p + 5, cmp);
    int time = 0;
    int completed = 0;
    while (completed != 5)
    {
        for (int i = 0; i < 5; i++)
        {
            if (p[i].arr_time <= time && p[i].remaining_time != 0)
            {
                p[i].remaining_time--;
                time++;
                if (p[i].remaining_time == 0)
                {
                    completed++;
                    p[i].wait_time = time - p[i].arr_time - p[i].burst_time;
                }
            }
            else
            {
                time++;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << p[i].id << " " << p[i].wait_time << endl;
    }
}
