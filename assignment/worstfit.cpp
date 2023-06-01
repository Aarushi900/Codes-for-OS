#include <stdio.h>
int main()
{
    int fragment[20], b[20], p[20], nb, np, temp, max = -1;
    static int ballocated[20], pallocated[20];
    printf("\n\t\t\tMemory Management Scheme - Worst Fit");
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

    // finding the worst fit of block for each process
    // max stores the maximum space left after assigning the block to the process
    for (int i = 1; i <= np; i++)
    {
        for (int j = 1; j <= nb; j++)
        {
            if (ballocated[j] != 1) // if the block is not assigned to any process
            {
                temp = b[j] - p[i]; // calculating the space left after assigning the block to the process
                if (temp >= 0)      // if the space left is positive
                    if (max < temp) // if the space left is more than the max
                    {
                        pallocated[i] = j; // assigning the block to the process
                        max = temp;        // updating the max
                    }
            }
        }
        // fragment stores the space left after assigning the block to the process
        fragment[i] = max;
        ballocated[pallocated[i]] = 1; // assigning the block to the process
        max = -1;                      // updating the max
    }
    // displaying the output
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (int i = 1; i <= np; i++)
        if (pallocated[i] != 0)
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], pallocated[i], ballocated[pallocated[i]], fragment[i]);
        else
            printf("\n%d\t\t%d\t\tNot Allocated", i, p[i]);
    return 0;
}
