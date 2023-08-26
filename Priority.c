#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], p[n], pid[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter burst time and priority for process %d: ", i + 1);
        scanf("%d %d", &bt[i], &p[i]);
        pid[i] = i + 1;
    }

    int i, j, a, m;
    for (i = 0; i < n - 1; i++)
    {
        a = p[i], m = i;
        for (j = i; j < n; j++)
        {
            if (p[j] > a)
            {
                a = p[j];
                m = j;
            }
        }
        swap(&p[i], &p[m]);
        swap(&bt[i], &bt[m]);
        swap(&pid[i], &pid[m]);
    }

    int time = 0;
    printf("Order of process execution is:-");
    for (i = 0; i < n; i++)
    {
        printf("P%d is executed from %d to %d\n", pid[i], time, time + bt[i]);
        time += bt[i];
    }
    printf("\n");

    printf("Process Id  Burst Time  Wait Time  TurnAround Time\n");
    int waitTime = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\t\t%d\n", pid[i], bt[i], waitTime, waitTime + bt[i]);
        waitTime += bt[i];
    }

    return 0;
}