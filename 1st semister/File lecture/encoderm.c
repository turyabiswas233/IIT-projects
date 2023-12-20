#include <stdio.h>
#include <stdlib.h>
void encoder(int *number);

int main(int argC, char *argV[])
{

    int number = atoi(argV[1]);

    encoder(&number);
    printf("encoded value: %d\n", number);

    encoder(&number);
    printf("encoded value: %d\n", number);
    return 0;
}

void encoder(int *number)
{
    struct bit
    {
        char a;
        char b;
    } x;

    union u
    {
        int num;
        struct bit x;
    } uni;

    uni.num = *number;
    char c;
    c = uni.x.a;
    uni.x.a = uni.x.b;
    uni.x.b = c;
    *number = uni.num;
}
