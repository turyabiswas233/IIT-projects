#include <stdio.h>
int main(int argc, char const *argv[])
{
    char *p, **mp, str[80];

    p = str;
    mp = &p;
    printf("Enter your name: ");
    gets(*mp);
    printf("Hi %s, \nWelcome to The world of PUBG\n", str);

    return 0;
}
