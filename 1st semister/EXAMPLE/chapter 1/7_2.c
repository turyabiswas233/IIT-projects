#include <stdio.h>

// prototype declare
void func1(void);
void func2(void);

int main(void)
{
    func2();
    printf("3");

    return 0;
}

void func2()
{
    func1(); // calling func1() function.
    printf("2 ");
}

void func1()
{
    printf("1 ");
}