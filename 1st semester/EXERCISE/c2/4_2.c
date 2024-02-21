#include <stdio.h>

int main()
{
    for (int i = 17; i <= 100; i++)
    {
        /* code */
        if (i % 17 == 0)

            printf("%d / %d = %d\n", i, 17, i / 17);
    }

    return 0;
}