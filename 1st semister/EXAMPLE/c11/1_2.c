#include <stdio.h>
#include <stdlib.h>
void f2(void);
void f(void);
int main(int argc, char const *argv[])
{
    register int a, b;
    a = 90;
    b = 999;
    printf("main-> %d %d\n", a, b);
    f();
    f2();

    return 0;
}
void f(void)
{
    register int i, j;
    i = 10;
    j = 190;
    printf("f-> %d %d\n", i, j);
}
void f2(void)
{
    register int k, j;
    j = 10;
    k = 190;
    printf("f2-> %d %d\n", j, k);
}
