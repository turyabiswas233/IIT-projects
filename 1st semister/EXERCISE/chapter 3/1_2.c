#include <stdio.h>
int main()
{
    for (int i = 0; i < 256; i++)
    {
        if (((char)i >= 'A' && (char)i <= 'Z') || ((char)i >= 'a' && (char)i <= 'z'))
            printf("%c - %d\n", (char)i, i);
    }
    printf("%c - %d", ' ', (int)' ');
    return 0;
}
