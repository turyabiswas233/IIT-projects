#include <stdio.h>

int main(int argc, char const *argv[])
{
    float *p, x = 53455.1651;
    printf("%d\n", 2);

    printf("OLD : %p = %d \n", p, *p);
    p = &x;
    printf("NEW : %p = %d \n", p, *p);
    p = (float *)0x1000;
    // *p = x;
    printf("NEW (x): %p  \n", p);

    return 0;
}
