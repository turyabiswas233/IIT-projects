#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp1, *fp2;
    int i;
    double d;
    if ((fp1 = fopen("count.txt", "rb")) == NULL)
    {
        printf("reading error\n");
        exit(1);
    }
    if ((fp2 = fopen("values.txt", "rb")) == NULL)
    {
        printf("reading error\n");
        exit(1);
    }
    fread(&i, sizeof i, 1, fp1);
    for (; i > 0; i--)
    {
        fread(&d, sizeof d, 1, fp2);
        printf("%lf\n", d);
    }
    fclose(fp1);
    fclose(fp2);
}

// hoisilo