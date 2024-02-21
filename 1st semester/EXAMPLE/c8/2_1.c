#include <stdio.h>
int main(void)
{
    char ch;
    do
    {
        ch = getchar();
        if (ch != '\n')
            putchar('.');
    } while (ch != '\n');
    return 0;
}