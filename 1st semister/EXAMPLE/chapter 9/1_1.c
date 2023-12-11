#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    char str[80] = "This is a file system test.\n";

    FILE *fp;
    char *p;
    int i;

    // open myfile for output
    if ((fp = fopen("myfile.txt", "w")) == NULL)
    {
        perror("cannot open the file\n");
        exit(1);
    }

    // write str to disk
    p = str;
    while (*p)
    {
        /* code */
        if (fputc(*p, fp) == EOF)
        {
            perror("Error writing file.\n");
            exit(1);
        }
        p++;
    }
    fclose(fp);
    // now open myfile in read mode

    if ((fp = fopen("myfile.txt", "r")) == NULL)
    {
        perror("Error file opeing...\n");
        exit(1);
    }
    for (;;)
    {
        i = fgetc(fp);
        if (i == EOF)
        {
            break;
        }
        putchar(i);
    }
    fclose(fp);

    return 0;
}
