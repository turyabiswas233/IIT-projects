#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    long loc;
    FILE *in, *out;
    char ch;

    if (argc != 3)
    {
        printf("Usage: revcopy <source> <destination>.\n");
        exit(1);
    }

    if ((in = fopen(argv[1], "rb")) == NULL)
    {
        printf("Error open input file\n");
        exit(1);
    }

    if ((out = fopen(argv[2], "wb")) == NULL)
    {
        printf("Error open output file\n");
        exit(1);
    }

    // find end of source file
    fseek(in, 0L, SEEK_END);
    loc = ftell(in);

    // copy file in reverse order
    loc = loc - 1;
    while (loc >= 0L)
    {
        fseek(in, loc, SEEK_SET);
        ch = fgetc(in);
        fputc(ch, out);
        loc--;
    }
    fclose(in);
    fclose(out);
    return 0;
}
