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
};
bool cmp(Process p1, Process p2)
{
    return p1.arr_time < p2.arr_time;
}
int main()
{
    Process p[5];
    for (int i = 0; i < 5; i++)
    {
        p[i].id = i + 1;
        cin >> p[i].arr_time >> p[i].burst_time;
    }
    sort(p, p + 5, cmp);
    int time = 0;
    int completed = 0;
    ;
    int q = 2;
    while (completed != 5)
    {
        for (int i = 0; i < 5; i++)
        {
            if (p[i].arr_time <= time && p[i].burst_time != 0)
            {
                p[i].burst_time -= q;
                time += q;
                if (p[i].burst_time == 0)
                {
                    completed++;
                    p[i].wait_time = time - p[i].arr_time;
                }
                else if (p[i].burst_time < 0)
                {
                    completed++;
                    time -= p[i].burst_time;
                    p[i].wait_time = time - p[i].arr_time;
                }
            }
            else
            {
                time += q;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << p[i].id << " " << p[i].wait_time << endl;
    }
}
