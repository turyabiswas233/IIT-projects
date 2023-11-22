#include <stdio.h>
void mystrcpy(char *to, char *from);
int main()
{

    char str[80];
    mystrcpy(str, "this is a test");
    printf("%s\n", str);
}

void mystrcpy(char *to, char *from)
{
    while (*from)
        *to++ = *from++;
    *to = '\0';
}