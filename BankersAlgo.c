#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    printf("Enter the number of processes and resources: ");
    int n, m;
    scanf("%d %d", &n, &m);

    int avail[m];
    printf("Enter the available resources: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    int alloc[n][m];
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    int max[n][m];
    printf("Enter the maximum requirement matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    bool completed[n];
    for (int i = 0; i < n; i++)
    {
        completed[i] = false;
    }

    int need[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int seq[n], count = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (!completed[i])
            {
                bool flag = false;

                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = true;
                        break;
                    }
                }

                if (!flag)
                {
                    seq[count++] = i;
                    for (int j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }
                    completed[i] = true;
                }
            }
        }
    }

    if (count == n)
    {
        printf("The following system is safe and can be scheduled as: ");
        for (int i = 0; i < n - 1; i++)
        {
            printf(" P%d ->", seq[i]);
        }
        printf(" P%d\n", seq[n - 1]);
    }
    else
    {
        printf("\nThe following system is not safe!");
    }
}