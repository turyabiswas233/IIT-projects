#include <stdio.h>
#include <stdlib.h>
struct telemetry
{
    unsigned fuel : 1;
    unsigned radio : 1;
    unsigned tv : 1;
    unsigned water : 1;
    unsigned food : 1;
    unsigned waste : 1;
} flt_read;

void display(struct telemetry i);

int main()
{
    FILE *fp;
    int i;

    if ((fp = fopen("flight.bin", "wb")) == NULL)
    {
        printf("cannot open file.\n");
        exit(1);
    }

    for (int i = 0; i < 100; i++)
    {
        flt_read.fuel = rand() % 2;
        flt_read.radio = rand() % 2;
        flt_read.tv = rand() % 2;
        flt_read.water = rand() % 2;
        flt_read.food = rand() % 2;
        flt_read.waste = rand() % 2;

        fwrite(&flt_read, sizeof flt_read, 1, fp);
        display(flt_read);
    }
    fclose(fp);
    return 0;
}

void display(struct telemetry i)
{
    if (i.fuel)
        printf("Fuel OK\n");
    else
        printf("Fuel low\n");
    if (i.radio)
        printf("Radio OK\n");
    else
        printf("Radio failure\n ");
    if (i.tv)
        printf("TV system OK\n");
    else
        printf("TV malfunction\n");
    if (i.water)
        printf("Water supply ok\n");
    else
        printf("Water supply low\n");
    if (i.food)
        printf("Food supply ok\n");
    else
        printf("Food supply low\n");
    if (i.waste)
        printf("Waste containment ok\n");
    else
        printf("Waste containment failure\n");
    printf("\n");
}