#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    int count = 0;
    char ch;
    fp = fopen("myfile.txt", "r");
    if (fp == NULL)
    {
        perror("Wrong file");
        exit(1);
    }
    while (1)
    {
        if ((ch = fgetc(fp)) == EOF)
        {
            break;
        }
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            count++;
    }
    printf("Total letters in file `myfile.txt` is %d\n", count);

    fclose(fp);

    return 0;
}
