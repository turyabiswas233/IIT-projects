#include <stdio.h>
int main(int argc, char const *argv[])
{
    int ans, count;
    for (count = 1; count < 11; count++)
    {
        /* code */
        printf("What is %d + %d ? ", count, count);
        scanf("%d", ans);

        if (ans == count * 2)
            printf("Right!\n");

        else
        {
            printf("sorry\n");
        }
    }

    return 0;
}
