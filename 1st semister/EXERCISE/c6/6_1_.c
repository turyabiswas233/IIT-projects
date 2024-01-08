#include <stdio.h>
int main()
{
    int i, *p, **q;
    p = &i;
    q = &p;
    **q = 100;
    printf("%d %p  %p  %p", i, &i, p, *q);
    return 0;
}