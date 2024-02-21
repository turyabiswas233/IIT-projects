#include <stdio.h>
#include <conio.h>
#include <ctype.h>
int main()
{
    char c;
    do
    {
        c = getch();
        cprintf("%c", tolower(c));
    } while (c != 'q');
}