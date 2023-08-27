#include <stdio.h>

int main()
{
    printf("Enter the number of processes: ");
    int n;
    scanf("%d", &n);

    printf("Enter the burst times of %d processes: ", n);
    int bt[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("\nThe FCFS cpu scheduling is as:\n");
    float waitingTime = 0, turnAroundTime = 0;
    int wt[n], tt[n];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            wt[0] = 0;
        }
        else
        {
            wt[i] = bt[i - 1] + wt[i - 1];
        }
        tt[i] = bt[i] + wt[i];
        printf("Process-%d:    Burst time-%d  Turnaround time-%d  Waiting time-%d\n", i + 1, bt[i], tt[i], wt[i]);
        waitingTime += wt[i];
        turnAroundTime += tt[i];
    }

    printf("\nThe average waiting time is: %0.2f", waitingTime / n);
    printf("\nThe average turn around time is: %0.2f", turnAroundTime / n);

    return 0;
}