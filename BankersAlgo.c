#include <stdio.h>

int main()
{
    int n, m;
    int i, j;

    printf("Enter the number of processes and resources: ");
    scanf("%d%d", &n, &m);

    int avail[m];
    printf("Enter the available resources: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }
    int alloc[n][m];
    printf("Enter the allocation matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    int max[n][m];
    printf("Enter the max matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    int k;
    int f[n], ans[n], ind = 0;

    for (i = 0; i < n; i++)
    {
        f[i] = 0;
    }

    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {

            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }

    if (flag == 1)
    {
        printf("The following system is safe and can be scheduled as : ");
        for (i = 0; i < n - 1; i++)
        {
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d", ans[n - 1]);
    }

    return (0);
}