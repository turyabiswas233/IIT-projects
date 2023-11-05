#include <stdio.h>
int main()
{
    char ch, preC;
    int nc, nw, nl;
    nc = nw = nl = 0;
    while (1)
    {
        /* code */

        if ((ch = getchar()) == EOF)
        {
            if (preC != '\n')
                nw++;
            break;
        }
        nc++;
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            nw++;
        }
        if (ch == '\n')
            nl++;
        preC = ch;
        if (ch >= 97 && ch <= 123)
        {
            putchar(ch - 32);
        }
        else if (ch >= 65 && ch <= 91)
        {
            putchar(ch + 32);
        }
        else
        {
            putchar(ch);
        }
    }
    printf("\n\nNo of chars= %d\n", nc);
    printf("No of words= %d\n", nw);
    printf("No of lines= %d\n", nl);

    return 0;
}