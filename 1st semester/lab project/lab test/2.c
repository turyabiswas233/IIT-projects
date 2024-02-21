#include <stdio.h>

int main()
{
    int cp, sp, gl;
    printf("Enter cost price: ");
    scanf("%d", &cp);
    printf("Enter sell price: ");
    scanf("%d", &sp);

    gl = sp - cp;

    printf("%s = %d\n", gl < 0 ? "LOSS" : "GAIN", gl > 0 ? gl : -gl);
    return 0;
}
