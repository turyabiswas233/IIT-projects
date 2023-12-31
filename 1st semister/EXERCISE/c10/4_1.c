#include <stdio.h>
#include <stdlib.h>
struct b_filed
{
    unsigned a : 3, b : 3, c : 2;
} bf;

int main(int argc, char const *argv[])
{
    bf.a = 2;
    bf.b = 20;
    bf.c = 200;

    printf("a:%d \n", bf.a);
    printf("b:%d \n", bf.b);
    printf("c:%d \n", bf.c);
    return 0;
}
