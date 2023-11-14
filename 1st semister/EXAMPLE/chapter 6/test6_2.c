#include <stdio.h>
int main(int argc, char const *argv[])
{
    int *p;
    int x=5;
    p = &x;
    
    printf("(*p)++: %d[%p]\n",++(*p),p);
    (*p)--;
    printf("--(*p): %d[%p]\n",--(*p),p);
    p++;
    printf("p++: %d[%p]\n",*p,p);


    
    return 0;
}
