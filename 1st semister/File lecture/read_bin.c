#include <stdio.h>
int main()
{
    FILE *fp, *fpo;

    fp = fopen("file.dat", "rb");
    fpo = fopen("out.txt", "w");

    char str[2000];
    fread(str, sizeof(str), 1, fp);

    fprintf(fpo, "%s", str);

    fclose(fp);
    fclose(fpo);
    return 0;
}
