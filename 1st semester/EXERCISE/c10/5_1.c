#include <stdio.h>
#include <stdlib.h>

union u_data
{
    double d;
    char c[8];
};

void wdtf(double value, const char *fileName)
{
    union u_data data;
    data.d = value;

    // open file in Binary
    FILE *fp;
    fp = fopen(fileName, "wb");
    if (fp == NULL)
    {
        printf("Error opening file for writing\n");
        return;
    }

    // write each character fo the double to the file
    for (int i = 0; i < 8; i++)
    {
        fputc(data.c[i], fp);
    }
    fclose(fp);
}

double rdff(const char *fileName)
{
    union u_data data;
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL)
    {
        printf("Error opening file for writing\n");
        return 0.0;
    }

    for (int i = 0; i < 8; i++)
    {
        data.c[i] = fgetc(fp);
    }

    fclose(fp);
    return data.d;
}

int main(void)
{
    double orgVal = 3121464.1415949, orgVal1;
    const char *filename = "doubleData.bin";

    wdtf(orgVal, filename);
    orgVal1 = rdff(filename);
    printf("%lf", orgVal1);
    return 0;
}