#include <stdio.h>

int FRAME_SIZE;

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
    printf("Enter the number of frames: ");
    scanf("%d", &FRAME_SIZE);

    printf("Enter number of pages: ");
    int referenceLength;
    scanf("%d", &referenceLength);

    printf("Enter reference string: ");
    int referenceString[referenceLength];
    for (int i = 0; i < referenceLength; i++)
    {
        scanf("%d", &referenceString[i]);
    }

    int frames[FRAME_SIZE];
    for (int i = 0; i < FRAME_SIZE; i++)
    {
        frames[i] = -1;
    }
    int frameIndex = 0;
    int pageFaults = 0;

    for (int i = 0; i < referenceLength; i++)
    {
        int currentPage = referenceString[i];

        if (!findPageInFrames(frames, currentPage, FRAME_SIZE))
        {

            frames[frameIndex] = currentPage;
            frameIndex = (frameIndex + 1) % FRAME_SIZE;
            pageFaults++;
        }

        printf("Frames: ");
        for (int j = 0; j < FRAME_SIZE; j++)
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

    printf("Total Page Faults: %d\n", pageFaults);
}