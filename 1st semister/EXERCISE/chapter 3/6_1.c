#include <stdio.h>
int main(int argc, char const *argv[])
{
    int counter = 0;
    for (int i = 2; i <= 1000; i++)
    {
        int flag = 0;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            printf("%d\n", i);
            counter++;
        }
    }
    printf("Count : %d\n", counter);

    return 0;
}
