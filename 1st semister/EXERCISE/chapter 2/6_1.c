#include <stdio.h>

int main()
{
    printf("|\ti\t|\tii\t|\tiii\t|\n");
    for (int i = 0; i < 49; i++)
    {
        /* code */
        printf("_");
    }
    printf("\n");
    for (int i = 1; i <= 10; i++)
    {
        /* code */
        printf("|\t%d\t|\t%d\t|\t%d\t|\n", i, i * i, i * i * i);
    }

    return 0;
}