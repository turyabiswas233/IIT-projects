#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
uint32_t mod(int);
int main(int argc, char const *argv[])
{
    FILE *fp;
    fp = freopen("inp.txt", "w", stdout);
    if (fp == NULL)
    {
        perror("Failed to open file\n");
        exit(EXIT_FAILURE);
    }
    int size = atoi(argv[1]);
    fprintf(fp, "%d\n", size);
    for (int i = 1; i <= size; i++)
    {
        uint32_t x = i + mod((rand() % 30));
        fprintf(fp, "%d ", x);
    }
    fclose(fp);

    return 0;
}
uint32_t mod(int x)
{
    return x < 0 ? -x : x;
}
