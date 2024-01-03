#include <stdio.h>
int main(int argc, char const *argv[])
{
    int table[10][3];
    int i = 0;
    while (i < 10)
    {
        table[i][0] = i + 1;
        table[i][1] = table[i][0] * table[i][0];
        table[i][2] = table[i][0] * table[i][1];
        i++;
    }
    i = 0;
    while (i < 10)
    {
        printf("%d, %d, %d,\n", table[i][0], table[i][1], table[i][2]);
        i++;
    }

    return 0;
}
