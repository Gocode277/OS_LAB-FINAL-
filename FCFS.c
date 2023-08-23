#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    float bt[n], wt[n], tt[n];

    printf("Enter the burst times of %d processes: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &bt[i]);
    }

    printf("\nThe details of the processes are as below:\nProcess\tBurst Time\tTurn Around Time\tWaiting Time\n");
    float waitingTime = 0, turnAroundTime = 0;
    for (i = 0; i < n; i++)
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
        printf("%d\t%f\t%f\t%f\n", i + 1, bt[i], tt[i], wt[i]);
        waitingTime += wt[i];
        turnAroundTime += tt[i];
    }

    printf("The average waiting time is: %f", waitingTime / (float)n);
    printf("\nThe average turn around time is: %f", turnAroundTime / n);

    return 0;
}