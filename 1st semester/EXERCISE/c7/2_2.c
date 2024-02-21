#include <stdio.h>
void f(void) {
    int i;
    printf("in f() \n");
    for(i=0;i<10;i++) f();
}
int main(int argc, char const *argv[])
{
    f(); // ## this will run infinite time!! 
    return 0;
}