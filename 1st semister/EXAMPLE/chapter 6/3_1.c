#include <stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    char str[50] = "Turya biswas";
    char *p;
    p = str;
    while (*p)
    {
        *p = toupper(*p);
        p++;
    }
    printf("%s", str);
    p = str;

    printf("\n");
    while (*p)
    {
        *p = tolower(*p);
        p++;
    }
    printf("%s\n", str);
    return 0;
}
