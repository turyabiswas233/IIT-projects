#include <stdio.h>
int main()
{
    int i, j;
    for (i = 0; i <= 10; i++)
    {
        
        if (i > 5)
        {
            for (j = 10; j > i; j--)
            {
                printf("*");
            }
            printf("\n");
        }
        else {
            for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
        }
    }
}