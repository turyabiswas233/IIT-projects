#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *from, *to;
    char ch;

    /* see if correct number of command line arguments */
    if (argc != 3)
    {
        perror("Usage: copy <source> <destination>\n");
        exit(1);
    }
    /* open source file */
    if ((from = fopen(argv[1], "rb")) == NULL)
    {
        perror("Cannot open source file\n");
        exit(1);
    }

    /* open destination file */
    if ((to = fopen(argv[2], "wb")) == NULL)
    {
        perror("Cannot open destination file\n");
        exit(1);
    }

    /* copy data from file to file in binary mode */
    while (!feof(from))
    {
        ch = fgetc(from);
        if (ferror(from))
        {

            printf("Error reading source file.\n");
            exit(1);
        }
        if (!feof(from))
            fputc(ch, to);
        if (ferror(to))
        {
            printf("Error writing dest ~nation file.\n ");
            exit(1);
        }
        if (fclose(from) == EOF)
        {
            printf("Error closing source file.\n");
            exit(1);
        }
    }

    return 0;
}
