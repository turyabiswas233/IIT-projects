#include <stdio.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    char ch;
    do
    {
        ch = getche();
    } while (ch != 'q');
    printf("Found the q");
    return 0;
}
