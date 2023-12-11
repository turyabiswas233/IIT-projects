#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    fp = fopen("demo.txt", "r");

    if (fp == NULL)
    {
        perror("No file found!");
        exit(1);
    }
    char str[1000];
    char chk;
    while (1)
    {
        fgets(str, 500, fp);
        puts(str);
        chk = getchar();
        if (chk == '\n')
        {
            continue;
        }
        if (chk == 'q')
            break;
    }

    fclose(fp);

    return 0;
}
