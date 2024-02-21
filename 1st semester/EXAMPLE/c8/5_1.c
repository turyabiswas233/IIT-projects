#include <stdio.h>
int main (void)
{
    printf("%.5d\n", 10);
    printf("$%.2f\n", 99.95);
    printf("%.10s", "not all of this will be printed\n");
    return 0;
}