#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int NUM_PHILOSOPHERS, NUM_CHOPSTICKS;

typedef struct
{
    int n;
    HANDLE left_chopstick;
    HANDLE right_chopstick;
} philosopher_data;

void dine(philosopher_data *data)
{
    int n = data->n;

    printf("\nPhilosopher %d is thinking ", n + 1);

    WaitForSingleObject(data->left_chopstick, INFINITE);
    WaitForSingleObject(data->right_chopstick, INFINITE);

    printf("\nPhilosopher %d is eating ", n + 1);
    Sleep(1000);

    ReleaseMutex(data->left_chopstick);
    ReleaseMutex(data->right_chopstick);

    printf("\nPhilosopher %d Finished eating ", n + 1);
}

int main(void)
{
    printf("Enter the number of philosophers: ");
    scanf("%d", &NUM_PHILOSOPHERS);

    if (NUM_PHILOSOPHERS <= 1)
    {
        printf("Number of philosophers should be greater than 1.\n");
        return 1;
    }

    NUM_CHOPSTICKS = NUM_PHILOSOPHERS;

    HANDLE chopstick[NUM_CHOPSTICKS];
    philosopher_data data[NUM_PHILOSOPHERS];
    HANDLE threads[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_CHOPSTICKS; i++)
    {
        chopstick[i] = CreateMutex(NULL, FALSE, NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        data[i].n = i;
        data[i].left_chopstick = chopstick[i];
        data[i].right_chopstick = chopstick[(i + 1) % NUM_CHOPSTICKS];

        threads[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)dine, &data[i], 0, NULL);
    }

    WaitForMultipleObjects(NUM_PHILOSOPHERS, threads, TRUE, INFINITE);
}