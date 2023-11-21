#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    /* code */
    char ptr[2][50];
    scanf("%s", ptr);
    int len = strlen(ptr);

    for (size_t i = len - 1; i >= 0; i--)
    {
        printf("%s ", ptr - i);
    }

    return 0;
}
