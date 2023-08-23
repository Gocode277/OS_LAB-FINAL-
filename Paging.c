#include <stdio.h>

int main(void)
{
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;

    printf("Enter the memory size : ");
    scanf("%d", &ms);

    printf("Enter the page size : ");
    scanf("%d", &ps);

    nop = ms / ps;
    printf("The no. of pages available in memory are : %d ", nop);

    printf("Enter number of processes : ");
    scanf("%d", &np);
    int s[np], fno[np][20];
    rempages = nop;
    for (i = 1; i <= np; i++)

    {
        printf("\nEnter no. of pages required for p[%d] : ", i);
        scanf("%d", &s[i]);

        if (s[i] > rempages)
        {
            printf("\nMemory is full!");
            break;
        }
        rempages = rempages - s[i];

        printf("\nEnter pagetable for p[%d] :  ", i);
        for (j = 0; j < s[i]; j++)
            scanf("%d", &fno[i][j]);
    }

    printf("\nEnter Logical Address to find Physical Address : ");
    printf("Enter process no. and pagenumber and offset : ");

    scanf("%d %d %d", &x, &y, &offset);

    if (x > np || y >= s[i] || offset >= ps)
        printf("\nInvalid Process or Page Number or offset!");

    else
    {
        pa = fno[x][y] * ps + offset;
        printf("\nThe Physical Address is : %d", pa);
    }
}