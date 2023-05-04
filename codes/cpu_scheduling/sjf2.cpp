#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
struct Process
{
    int arr_time;
    int id;
    int burst_time;
    int wait_time;
};
bool comp(Process i1, Process i2)
{
    if (i1.arr_time != i2.arr_time)
    {
        return i1.arr_time < i2.arr_time;
    }
    else
    {
        return i1.burst_time < i2.burst_time;
    }
}
int main()
{
    Process p[5];
    for (int i = 0; i < 5; i++)
    {
        p[i].id = i + 1;
        cin >> p[i].arr_time >> p[i].burst_time;
    }
    sort(p, p + 5, comp);
    int time = 0;
    int complete = 0;
    while (complete != 5)
    {
        int min = INT_MAX;
        int index = -1;
        for (int i = 0; i < 5; i++)
        {
            if (p[i].arr_time <= time && p[i].burst_time < min && p[i].burst_time != 0)
            {
                min = p[i].burst_time;
                index = i;
            }
        }
        if (index != -1)
        {
            p[index].burst_time--;
            if (p[index].burst_time == 0)
            {
                complete++;
                p[index].wait_time = time - p[index].arr_time;
            }
            cout << p[index].id << " " << time << endl;
        }
        time++;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << p[i].id << " " << p[i].wait_time << endl;
    }
}