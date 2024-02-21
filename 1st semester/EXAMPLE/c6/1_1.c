#include <stdio.h>
int main(int argc, char const *argv[])
{
    int *p,q;
    p = &q;
    *p = 1000;
    printf("%d", q);
    return 0;
}
