#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    printf("Enter the number of requests: ");
    int n;
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    int req[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter the initial head position: ");
    int head;
    scanf("%d", &head);

    printf("\nThe seek sequence is as: ");
    int count = 0, headmovement = 0;

    bool processed[n];
    for (int i = 0; i < n; i++)
    {
        processed[i] = false;
    }

    while (count < n)
    {
        int min = 99999, index;
        for (int i = 0; i < n; i++)
        {
            if (!processed[i])
            {
                int dist = abs(req[i] - head);
                if (dist < min)
                {
                    min = dist;
                    index = i;
                }
            }
        }
        printf("%d  ", req[index]);
        headmovement += min;
        head = req[index];
        processed[index] = true;
        count++;
    }

    printf("\nTotal head movement is: %d\n", headmovement);
}