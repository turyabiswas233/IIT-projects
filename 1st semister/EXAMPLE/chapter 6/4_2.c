#include <stdio.h>
#include <string.h>
#define InsDisk "Insert disk into drive A, then press ENTER...\n"

int main(int argc, char const *argv[])
{
    char *str;

    do
    {
        printf(InsDisk);
        gets(str);
    } while (strcmp(str, "A"));

    return 0;
}
