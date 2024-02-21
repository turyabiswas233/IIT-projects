#include <stdio.h>
void f1(int a);
void f2(int a);
int main(int argc, char const *argv[])
{
    f1(30);
    return 0;
}
void f1(int a) {
    if(a) f2(a-1);
    printf("%d ",a);
}
void f2(int a) {
    printf(".");
    if(a) f1(a-1);
}
