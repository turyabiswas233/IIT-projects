#include <stdio.h>
int main(void)
{
    int i;
    i = 10;
    printf("This is i: %d\n", i);

    i = -i;

    printf("This is updated i: %d\n", i);
    return 0;
}