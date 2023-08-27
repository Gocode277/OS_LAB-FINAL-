#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nThe first fit allocation is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process-%d:  Size-%d", i + 1, processSize[i]);
        if (allocation[i] != -1)
        {
            printf("  Allocated-%d", allocation[i] + 1);
        }
        else
        {
            printf("  Not Allocated");
        }
        printf("\n");
    }
}

int main(void)
{
    printf("Enter the number of blocks: ");
    int m;
    scanf("%d", &m);

    printf("Enter the block sizes: ");
    int blockSize[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    int n;
    scanf("%d", &n);

    printf("Enter the process sizes: ");
    int processSize[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processSize[i]);
    }

    firstFit(blockSize, m, processSize, n);
}
