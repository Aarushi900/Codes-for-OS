#include <bits/stdc++.h>
using namespace std;
int main()
{
    int pro[] = {1, 2, 3};
    int n = 3;
    int bur[] = {10, 5, 8};
    int wt[n], tn[n];
    int t = 0, rem[n], tq = 2;

    for (int i = 0; i < n; i++)
        rem[i] = bur[i];
    int completed = 0;
    while (completed != n)
    {
        for (int i = 0; i < n; i++)
        {
            if (rem[i] > 0)
            {

                if (rem[i] > tq)
                {
                    t += tq;
                    rem[i] -= tq;
                }
                else
                {
                    t += rem[i];
                    wt[i] = t - bur[i];
                    rem[i] = 0;
                    completed++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        tn[i] = wt[i] + bur[i];
    }
    cout << "PN\t "
         << " \tBT "
         << "  WT "
         << " \tTAT\n";

    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << bur[i] << "\t "
             << wt[i] << "\t\t " << tn[i] << endl;
    }
    return 0;
}