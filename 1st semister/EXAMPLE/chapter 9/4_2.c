#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{

    FILE *fp;
    double ld;
    int d;
    char str[80];

    if (argc != 5)
    {
        printf("Specify file name. \n");
        exit(1);
    }

    if ((fp = fopen(argv[1], "w")) == NULL)
    {
        printf("Cannot open file. \n");
        exit(1);
    }
    fprintf(fp, "%f %d %s", atof(argv[2]), atoi(argv[3]), argv[4]);
    fclose(fp);

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open file. \n ");
        exit(1);
    }
    fscanf(fp, "%lf%d%s", &ld, &d, str);
    printf("%f %d %s", ld, d, str);

    fclose(fp);
    return 0;
}