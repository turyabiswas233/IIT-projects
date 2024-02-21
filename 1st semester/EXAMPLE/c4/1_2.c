#include <stdio.h>
int main()
{
    short int i;
    unsigned short int u;
    u = 33000;
    i = u;
    printf("%hd %hu\n", i, u);
}