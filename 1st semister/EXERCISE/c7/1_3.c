#include <stdio.h>
double myfunc(double *num);
int main(void)
{
    double d;
    scanf("%lf", &d);
    printf("%lf", myfunc(&d));
}
double myfunc(double *num)
{
    return *num / 2.0;
}