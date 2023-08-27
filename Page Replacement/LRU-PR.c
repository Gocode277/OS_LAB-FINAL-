#include <stdio.h>

int findLRU(int time[], int n)
{
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; ++i)
    {
        if (time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main(void)
{
    printf("Enter number of frames: ");
    int no_of_frames;
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    int no_of_pages;
    scanf("%d", &no_of_pages);

    printf("Enter page sequence: ");
    int pages[no_of_pages];
    for (int i = 0; i < no_of_pages; ++i)
    {
        scanf("%d", &pages[i]);
    }

    int frames[no_of_frames];
    for (int i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }

    printf("\nLRU page replacement process:\n");

    int counter = 0, flag1, flag2, pos, faults = 0, time[no_of_frames];
    for (int i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for (int j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (int j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        for (int j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == -1)
            {
                printf("- ");
            }
            else
            {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("\nTotal page faults: %d", faults);
}