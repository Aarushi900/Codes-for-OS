#include <stdio.h>
int main()
{
    int fragment[20], b[20], p[20], nb, np, temp, lowest = 9999;
    static int ballocated[20], pallocated[20];
    printf("\n\t\t\tMemory Management Scheme - Best Fit");
    // entering the number of memory blocks
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    // entering the number of processes
    printf("Enter the number of processes:");
    scanf("%d", &np);
    // entering the size of the blocks
    printf("\nEnter the size of the blocks:-\n");
    for (int i = 1; i <= nb; i++)
    {
        printf("Block no.%d:", i);
        scanf("%d", &b[i]);
    }
    // entering the size of the processes
    printf("\nEnter the size of the processes :-\n");
    for (int i = 1; i <= np; i++)
    {
        printf("Process no.%d:", i);
        scanf("%d", &p[i]);
    }
    // initially no block is assigned to any process
    // so all the values of the array barray is 0
    // barray is the block array
    for (int i = 1; i <= np; i++)
        ballocated[i] = 0;

    // initially no process is assigned to any block
    // so all the values of the array parray is 0
    // parray is the process array
    for (int i = 1; i <= np; i++)
        pallocated[i] = 0;

    // finding the best fit of block for each process
    // lowest stores the minimum space left after assigning the block to the process
    for (int i = 1; i <= np; i++)
    {
        for (int j = 1; j <= nb; j++)
        {
            if (ballocated[j] != 1) // if the block is not assigned to any process
            {
                temp = b[j] - p[i];    // calculating the space left after assigning the block to the process
                if (temp >= 0)         // if the space left is positive
                    if (lowest > temp) // if the space left is less than the minimum space left
                    {
                        pallocated[i] = j; // assigning the block to the process
                        lowest = temp;     // updating the minimum
                    }
            }
        }
        // fragment stores the space left after assigning the block to the process
        fragment[i] = lowest;
        ballocated[pallocated[i]] = 1; // assigning the block to the process
        lowest = 10000;                // updating the minimum
    }
    // displaying the output
    for (int i = 1; i <= np; i++)
        if (pallocated[i] != 0)
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], pallocated[i], ballocated[pallocated[i]], fragment[i]);
        else
            printf("\n%d\t\t%d\t\tNot Allocated", i, p[i]);
    return 0;
}
