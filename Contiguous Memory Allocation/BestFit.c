#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;

        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                {
                    bestIdx = j;
                }
                else if (blockSize[bestIdx] > blockSize[j])
                {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
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

    bestFit(blockSize, m, processSize, n);
}
