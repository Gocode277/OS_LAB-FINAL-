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
            avail[j] -= alloc[i][j];
        }
    }

    int req[n][m];
    printf("Enter the request matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &req[i][j]);
        }
    }

    bool completed[n];
    for (int i = 0; i < n; i++)
    {
        completed[i] = false;
    }

    int count = 0;
    while (count < n)
    {
        bool safe = false;
        for (int i = 0; i < n; i++)
        {
            if (!completed[i])
            {
                bool canExecute = true;
                for (int j = 0; j < m; j++)
                {
                    if (req[i][j] > avail[j])
                    {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute)
                {
                    for (int j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }
                    completed[i] = true;
                    safe = true;
                    count++;
                    break;
                }
            }
        }

        if (!safe)
        {
            break;
        }
    }

    if (count == n)
    {
        printf("\nThe following system is safe!");
    }
    else
    {
        printf("\nThe following system is not safe!");
    }
}