#include <stdio.h>
double *Purge();
int main(int argc, char const *argv[])
{
    printf("%p", Purge());
    return 0;
}

double *Purge()
{
    return Purge();
}