#include <stdio.h>
int main()
{
    for (int i = 1; i <= 100/5; i++)
    {
        /* code */
        for (int j = i; j <= 100; j += 100/5)
        {
            /* code */
            printf("%5d", j);
        }
        printf("\n");
    }

    return 0;
}
