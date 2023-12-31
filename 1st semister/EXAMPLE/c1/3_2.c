#include <stdio.h>
int main(void)
{
    // different data-type variables
    char ch;
    float f;
    double d;

    // assigning value inside referance variable(s)
    ch = 'X';
    f = 100.123;
    d = 123.009;

    // printing data in terminal
    printf("ch is %c\n", ch);
    printf("f is float %.3f\n", f);
    printf("d is %.3lf\n", d);

    return 0;
}