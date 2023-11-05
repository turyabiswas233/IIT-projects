#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);

    for (int i = a; i >= 0; i--)
    {
        /* code */

        printf("%d\n", i);
        if (i == 0)
        {
            printf("BELL!!\n");
        }
    }

    return 0;
}