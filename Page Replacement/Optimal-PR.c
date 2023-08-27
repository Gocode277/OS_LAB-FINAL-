#include <stdio.h>

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

    printf("\nOptimal page replacement process:\n");

    int temp[no_of_frames], flag1, flag2, flag3, pos, max, faults = 0;
    for (int i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for (int j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
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
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            flag3 = 0;

            for (int j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1;

                for (int k = i + 1; k < no_of_pages; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (int j = 0; j < no_of_frames; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;

                for (int j = 1; j < no_of_frames; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            faults++;
        }

        for (int j = 0; j < no_of_frames; j++)
        {
            if (frames[j] != -1)
            {
                printf("%d ", frames[j]);
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("\nTotal page faults: %d", faults);
}