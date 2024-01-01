#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int add, sub, mul, div, a, b;
    a = atoi(argv[2]);
    b = atoi(argv[3]);

    add = strcmp(argv[1], "add");
    mul = strcmp(argv[1], "multiply");
    sub = strcmp(argv[1], "subtract");
    div = strcmp(argv[1], "divide");

    if (!add)
    {
        printf("%d", a + b);
    }
    else if (!sub)
    {
        printf("%d", a - b);
    }
    else if (!mul)
    {
        printf("%d", a * b);
    }
    else if (!div)
    {
        printf("%d", a / b);
    }
    else
    {
        printf("wrong operation!!");
    }
    printf("\n");

    return 0;
}
