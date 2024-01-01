#include <stdio.h>
int fact(int n) {
    if(n<-1) return -1;
    if(n==1) return 1;
    if(n>0) return n*fact(n-1);
}
int main(int argc, char const *argv[])
{
    printf("%d", fact(10));
    return 0;
}
