#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    char str[80];
    if (argc != 2)
    {
        printf("Specify file name\n");
        exit(1);
    }

    if ((fp = fopen(argv[1], "w")) == NULL)
    {
        printf("cannot open file\n");
        exit(1);
    }

    printf("Enter a blank line to stop.\n");

    do
    {
        printf("(*): ");
        gets(str);
        strcat(str, "\n");
        if (*str != '\n')
            ;
        fputs(str, fp);
    } while (*str != '\n');

    fclose(fp);

    // now open file for input
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open file.\n ");
        exit(1);
    }

    // read back the file
    do
    {
        fgets(str, 90, fp);
        if (!feof(fp))
            puts(str);
    } while (!feof(fp));
    fclose(fp);
    return 0;
}
