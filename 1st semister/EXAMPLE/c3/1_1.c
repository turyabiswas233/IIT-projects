#include <stdio.h>
#include <conio.h>
int main()
{
    char ch;
    printf("Enter a character: ");
    ch = getch();
    printf("%c\nIts ascii code is %d", ch, ch);
}