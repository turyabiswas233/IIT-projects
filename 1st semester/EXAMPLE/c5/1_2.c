#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a1[10], a2[10];
    int i;
    for ( i = 1; i <11; i++) a1[i-1] = i;
    for ( i = 1; i <11; i++) a2[i-1] = a1[i-1];
    
    for ( i = 0; i <10; i++) printf("%d ", a2[i]);
    
    return 0;
}
