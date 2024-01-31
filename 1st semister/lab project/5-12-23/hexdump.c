#include <stdio.h>
int printHex(unsigned char c, int i);
int main()
{
    char c;
    int i = 0;
    while ((c = getchar()) != EOF)
    {
        printHex(c, i);
        i++;
    }

    return 0;
}

int printHex(unsigned char c, int i)
{
    if (i == 0)
        printf("%06x", i);
    else
    {
        if (i % 16 == 0)
            printf("\n%06x ", i);
        else if (i % 16 == 8)
            printf(" -- ");
        else
        {
            printf(" ");
        }
    }
    
    printf("%0x04", c);
    return 0;
}
