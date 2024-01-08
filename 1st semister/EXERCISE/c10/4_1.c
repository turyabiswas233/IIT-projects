#include <stdio.h>
#include <stdlib.h>
struct b_filed
{
    unsigned a : 3;
    unsigned b : 3;
    unsigned c : 2;
} bf;

int main(int argc, char const *argv[])
{
    bf.a = 7;
    bf.b = 4;
    bf.c = 3;

    printf("a:%d \n", bf.a);
    printf("b:%d \n", bf.b);
    printf("c:%d \n", bf.c);
    return 0;
}
