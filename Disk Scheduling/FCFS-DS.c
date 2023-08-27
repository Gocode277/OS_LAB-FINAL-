#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int size;

void FCFS(int arr[], int head)
{
    int seek_count = 0;
    int cur_track, distance;

    for (int i = 0; i < size; i++)
    {
        cur_track = arr[i];
        distance = fabs(head - cur_track);
        seek_count += distance;
        head = cur_track;
    }

    printf("Total number of seek operations: %d\n", seek_count);
    printf("Seek Sequence is: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int main(void)
{
    printf("Enter the size of req array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int head;
    printf("Enter the head: ");
    scanf("%d", &head);

    FCFS(arr, head);
}