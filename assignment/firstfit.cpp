#include <stdio.h>
int main()
{
    int fragment[20], b[20], p[20], nb, np;
    static int ballocated[20], pallocated[20];
    printf("\n\t\t\tMemory Management Scheme - first Fit");
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

    // finding the first fit of block for each process
    for (int i = 1; i <= np; i++)
    {
        for (int j = 1; j <= nb; j++)
        {
            if (ballocated[j] != 1 && b[j] >= p[i]) // if the block is not assigned to any process &&& if the block size is greater than the process size
            {
                pallocated[i] = j; // assigning the block to the process
                break;
            }
        }
        // fragment stores the space left after assigning the block to the process
        fragment[i] = b[pallocated[i]] - p[i];
        ballocated[pallocated[i]] = 1; // assigning the block to the process
    }
    // displaying the output
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (int i = 1; i <= np && pallocated[i] != 0; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], pallocated[i], ballocated[pallocated[i]], fragment[i]);
    return 0;
}
