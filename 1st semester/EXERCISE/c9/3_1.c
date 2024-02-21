#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("myfile.txt", "r");
    int i;
    char ch;
    for (i = 0;; i++)
        if ((ch = fgetc(fp)) == EOF)
            break;
    printf("Total bytes: %dB\n ", i);

    fclose(fp);

    return 0;
}
