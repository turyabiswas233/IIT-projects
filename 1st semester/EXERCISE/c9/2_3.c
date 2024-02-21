#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    // copy paste
    FILE *ifp, *ofp;
    char ch;
    ifp = fopen(argv[1], "r");
    if (ifp == NULL)
    {
        exit(1);
    }

    ofp = fopen(argv[2], "w");
    fprintf(ofp, "----- copy from `%s` to `%s` -----\n", argv[1], argv[2]);
    printf("----- copy from `%s` to `%s` -----\n", argv[1], argv[2]);
    while (1)
    {
        if ((ch = fgetc(ifp)) == EOF)
            break;
        fputc(ch, ofp);
        printf("%c", ch);
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}
