#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i;
int main(int argc, char const *argv[])
{
    register int j;
    int k;
    clock_t start, finish;

    start = clock();
    for (k = 0; k < 100; k++)
        for (i = 0; i < 32000; i++)
            ;
    finish = clock();
    printf("Non-register loop: %d ticks\n", finish - start);

    start = clock();
    for (k = 0; k < 100; k++)
        for (j = 0; j < 32000; j++)
            ;
    finish = clock();
    printf("Register loop: %d ticks\n", finish - start);

    return 0;
}
