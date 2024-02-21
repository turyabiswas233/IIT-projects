#include <stdio.h>
void f1(void), f2(void);

int main()
{
    f1();
    f2();
    return 0;
}

void f1(void)
{
    printf("khali 1\n");
}
void f2(void)
{
    printf("khali 2\n");
}