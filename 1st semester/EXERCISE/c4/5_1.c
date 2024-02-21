#include <stdio.h>
int main(int argc, char const *argv[])
{
    char ch;
    short i;
    unsigned long ul;
    float f;
    ch = 'A';
    i = 32;
    ul = 2;
    f = 65 * 2.5;
    printf("%f, %d\n", f / ch - (i * ul), f / ch - (i * ul));
    printf("size(f): 0x%02x\nsize(ul): 0x%02x\n", 0xFF & sizeof(f), 0xFF & sizeof(ul));
    return 0;
}
