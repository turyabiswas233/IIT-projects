#include <stdio.h>
int main()
{
    FILE *fp, *fpo;
    fp = fopen("file.txt", "r");
    fpo = fopen("file.dat", "wb");

    char c;

    while ((c = fgetc(fp)) != EOF)
    {
        // fscanf
        // fprintf
        fwrite(&c, sizeof(c), 1, fpo);
    }

    fclose(fp);
    fclose(fpo);

    return 0;
}

/*

    write = w / wb
    read = r / rb
    append = a / ab
*/