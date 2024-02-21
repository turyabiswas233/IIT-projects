#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i;
    for (i = 0; i < 1000; i++)
        printf("%10d %10d %10d\n", rand() % 1000, rand() % 1000, rand() % 1000);
    return 0;
}