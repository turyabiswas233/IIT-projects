#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL) // input "myfile.txt"
    {
        perror("file not found");
        exit(1);
    }
    char ch;
    for (;;)
    {
        if ((ch = fgetc(fp)) == EOF)
            break;
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}
