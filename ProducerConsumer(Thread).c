#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int mutex = 1;
int full = 0;
int empty = 10, x = 0;

HANDLE mutex_lock; // Mutex handle

DWORD WINAPI producer(LPVOID arg)
{
    while (1)
    {
        WaitForSingleObject(mutex_lock, INFINITE); // Lock the mutex
        if (empty > 0)
        {
            --empty;
            ++full;
            ++x;
            printf("Producer produces item: %d\n", x);
        }
        else
        {
            printf("Buffer is full!\n");
        }
        ReleaseMutex(mutex_lock); // Unlock the mutex
    }
    return 0;
}

DWORD WINAPI consumer(LPVOID arg)
{
    while (1)
    {
        WaitForSingleObject(mutex_lock, INFINITE); // Lock the mutex
        if (full > 0)
        {
            --full;
            ++empty;
            printf("Consumer consumes item: %d\n", x--);
        }
        else
        {
            printf("Buffer is empty!\n");
        }
        ReleaseMutex(mutex_lock); // Unlock the mutex
    }
    return 0;
}

int main(void)
{
    HANDLE producer_thread, consumer_thread;

    mutex_lock = CreateMutex(NULL, FALSE, NULL); // Create a mutex

    // Create producer and consumer threads
    producer_thread = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    consumer_thread = CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    // Wait for threads to finish (this will never happen in this example)
    WaitForSingleObject(producer_thread, INFINITE);
    WaitForSingleObject(consumer_thread, INFINITE);

    CloseHandle(mutex_lock); // Close the mutex handle

    return 0;
}
