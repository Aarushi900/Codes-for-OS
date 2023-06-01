#include <stdio.h>
#include <stdbool.h>

void nextProcess(int queue[], int n, int selected_proc)
{
    int next;
    for (int i = 0; i < n; i++)
    {
        if (queue[i] == 0)
        {
            next = i;
            break;
        }
    }
    queue[next] = selected_proc + 1;
}

void selectProcess(int queue[], int n)
{ // place a proc fwd if its in readyQueue
    for (int i = 0; (i < n - 1) && (queue[i + 1] != 0); i++)
    {
        int temp = queue[i];
        queue[i] = queue[i + 1];
        queue[i + 1] = temp;
    }
}

void newRequest(int curr_time, int at[], int n, int selected_proc, int queue[])
{
    if (curr_time <= at[n - 1])
    { // task is still pending
        bool newArrival = false;
        for (int j = selected_proc + 1; j < n; j++)
        {
            if (at[j] <= curr_time)
            {
                if (selected_proc < j)
                {
                    selected_proc = j;
                    newArrival = true;
                }
            }
        }

        if (newArrival)
        {
            nextProcess(queue, n, selected_proc);
        }
    }
}

int main()
{
    int n, tq, sumWait = 0, sumTAT = 0, selected_proc = 0; // index of proc selected
    printf("Enter no of proc and time quanta: ");
    scanf("%d %d", &n, &tq);

    int at[n], bt[n], rt[n], wt[n], tat[n], queue[n], curr_time = 0, idle_time = 0;
    bool is_complete[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival, burst time for proc %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        queue[i] = 0;
        is_complete[i] = false;
    }

    while (curr_time != at[0])
    {
        curr_time++;
    }

    queue[0] = 1;

    while (true)
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (rt[i] != 0)
            { // even if one proc is running
                flag = false;
                break;
            }
        }

        if (flag) // all procs have finished
            break;

        for (int i = 0; (i < n) && (queue[i] != 0); i++)
        { // proc is in readyQueue
            int ctr = 0;
            while ((ctr < tq) && (rt[queue[0] - 1] > 0))
            {
                rt[queue[0] - 1]--; // rem time for proc in readyQueue
                curr_time++;
                ctr++;
                newRequest(curr_time, at, n, selected_proc, queue);
            }

            if ((rt[queue[0] - 1] == 0) && (is_complete[queue[0] - 1] == false))
            {
                tat[queue[0] - 1] = curr_time;
                is_complete[queue[0] - 1] = true;
            }

            bool idle = true;
            if (queue[n - 1] == 0)
            {
                for (int i = 0; i < n && queue[i] != 0; i++)
                {
                    if (is_complete[queue[i] - 1] == false)
                    {
                        idle = false; // if atleast one proc is in readyQueue
                    }
                }
            }
            else
            {
                idle = false;
            }

            if (idle)
            {
                curr_time++;
                newRequest(curr_time, at, n, selected_proc, queue);
            }

            selectProcess(queue, n);
        }
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] -= at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nPId\tArr\tBT\tWait\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sumWait += wt[i];
        sumTAT += tat[i];
    }

    printf("\nAverage wait time: %f", (float)sumWait / n);
    printf("\nAverage Turn Around Time: %f\n", (float)sumTAT / n);
}
