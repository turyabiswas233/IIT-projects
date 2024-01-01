#include <stdio.h>
double *Purge();
double x = 100;
int main(int argc, char const *argv[])
{

    printf("%08u\n", &x);
    printf("%08u", Purge());
    return 0;
}

double *Purge()
{
    return &x;
}