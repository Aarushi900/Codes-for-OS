// RR
// Same arrival time as 0
#include <iostream>
using namespace std;

int main()
{
    int q, n, sum1 = 0, sum2 = 0;
    cout << "Enter time quantum: ";
    cin >> q;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], wt[n], tat[n], left_bt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i << "\nBurst Time: ";
        cin >> bt[i];
        tat[i] = 0;
        wt[i] = 0;
        left_bt[i] = bt[i];
    }
    // CALCULATING WAITING TIME
    bool RUN = true;
    while (RUN)
    {
        for (int i = 0; i < n; i++)
        {
            if (left_bt[i] > 0)
            {
                left_bt[i] = left_bt[i] - q;
                if (left_bt[i] == 0)
                {
                    tat[i] += q;
                }
                else if (left_bt[i] < 0)
                {
                    tat[i] = wt[i] + q + bt[i];
                }
                else
                {
                    tat[i] += q;
                }
            }
            else
            {
                continue;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (left_bt[i] > 0)
            {
                RUN = true;
                break;
            }
            else
            {
                RUN = false;
            }
        }
    }

    cout << "\n\nThe processes are scheduled as follows\n\n";
    cout << "Process \t\t\t Waiting Time \t\t\t Turn around Time\n";
    for (int j = 0; j < n; j++)
    {
        wt[j] = tat[j] - bt[j];
        sum2 += tat[j];
        sum1 += wt[j];
        cout << "P" << j + 1 << "\t\t\t\t\t" << wt[j] << "\t\t\t\t" << tat[j] << endl;
    }

    cout << "\nThe average waiting time: " << sum1 / n;
    cout << "\nThe average turnaround time: " << sum2 / n;
}