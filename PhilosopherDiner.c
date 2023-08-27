#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int NUM_PHILOSOPHERS, NUM_CHOPSTICKS;

typedef struct
{
    int n;
    HANDLE *chopstick;
} philosopher_data;

void dine(philosopher_data *data)
{
    int n = data->n;
    HANDLE *chopstick = data->chopstick;

    printf("\nPhilosopher %d is thinking ", n + 1);

    WaitForSingleObject(chopstick[n], INFINITE);
    WaitForSingleObject(chopstick[(n + 1) % NUM_CHOPSTICKS], INFINITE);

    printf("\nPhilosopher %d is eating ", n + 1);
    Sleep(3000);

    ReleaseMutex(chopstick[n]);
    ReleaseMutex(chopstick[(n + 1) % NUM_CHOPSTICKS]);

    printf("\nPhilosopher %d Finished eating ", n + 1);
}

int main(void)
{
    int i, status_message;
    void *msg;

    printf("Enter the number of philosophers: ");
    scanf("%d", &NUM_PHILOSOPHERS);
    NUM_CHOPSTICKS = NUM_PHILOSOPHERS;

    HANDLE philosopher[NUM_PHILOSOPHERS];
    HANDLE chopstick[NUM_CHOPSTICKS];
    philosopher_data data[NUM_PHILOSOPHERS];

    for (i = 0; i < NUM_CHOPSTICKS; i++)
    {
        chopstick[i] = CreateMutex(NULL, FALSE, NULL);

        if (chopstick[i] == NULL)
        {
            printf("\n Mutex initialization failed");
            exit(1);
        }
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        data[i].n = i;
        data[i].chopstick = chopstick;
        philosopher[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)dine, &data[i], 0, NULL);

        if (philosopher[i] == NULL)
        {
            printf("\n Thread creation error \n");
            exit(1);
        }
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        status_message = WaitForSingleObject(philosopher[i], INFINITE);

        if (status_message != 0)
        {
            printf("\n Thread join failed \n");
            exit(1);
        }
    }

    for (i = 0; i < NUM_CHOPSTICKS; i++)
    {
        status_message = CloseHandle(chopstick[i]);

        if (status_message == 0)
        {
            printf("\n Failed to destroy mutex \n");
            exit(1);
        }
    }
}