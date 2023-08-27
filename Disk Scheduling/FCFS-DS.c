#include <stdio.h>
#include <stdlib.h>

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
    int headmovement = 0;

    for (int i = 0; i < n; i++)
    {
        printf("%d  ", req[i]);
        int dist = abs(head - req[i]);
        head = req[i];
        headmovement += dist;
    }

    printf("\nTotal head movement is: %d\n", headmovement);
}