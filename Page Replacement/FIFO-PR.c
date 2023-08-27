#include <stdio.h>

int findPageInFrames(int frames[], int page, int frameCount)
{
    for (int i = 0; i < frameCount; i++)
    {
        if (frames[i] == page)
        {
            return 1;
        }
    }
    return 0;
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

    printf("\nFIFO page replacement process:\n");

    int faults = 0,frameIndex = 0;
    for (int i = 0; i < no_of_pages; i++)
    {
        int currentPage = pages[i];

        if (!findPageInFrames(frames, currentPage, no_of_frames))
        {

            frames[frameIndex] = currentPage;
            frameIndex = (frameIndex + 1) % no_of_frames;
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