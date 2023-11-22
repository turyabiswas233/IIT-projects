#include <stdio.h>
void myputs(char *p)
{
    while (*p)
    {
        printf("%c", *p);
        p++;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    myputs("this is a test");
    return 0;
}
