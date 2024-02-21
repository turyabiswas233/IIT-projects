#include <stdio.h>
#include <string.h>
#define STOP "stop"
int main(int argc, char const *argv[])
{

    char *str;
    do
    {
        printf("Enter a string: ");
        gets(str);
    } while (strcmp(STOP, str));

    return 0;
}
