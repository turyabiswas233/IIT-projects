#include <stdio.h>
#include <stdlib.h>
int ReadHeadStream(char *dst, int count, FILE *ifp);

int main()
{
    int rid, pll;
    unsigned int i = 0;
    unsigned char payload[2048];
    FILE *fp;

    if ((fp = fopen("D_File.dat", "rb")) == NULL)
    {
        exit(1);
    }
    int x = 1;
    while (1)
    {
        // in each loop, it will set new data to payload from current address(in *fp) from 0 to 4 index
        if ((ReadHeadStream(payload, 4, fp)) == 1)
        {
            putchar('\n');
            fclose(fp);
            return 0; // exit the program on EOF of the file
        }

        rid = payload[0] + payload[1];
        pll = payload[2] + payload[3];

        // printf("\trid=%d, pll=%d\n", rid, pll);

        if ((ReadHeadStream(payload, pll, fp)) == 1)
        {
            putchar('\n');
            exit(1);
        }

        printf("\n\nRecord no. %03d:\n    RID: 0x%04d", x, rid);
        if (rid == 1)
        {
            printf(" (ASCII Text)\n");
            for (i = 0; i < pll; i++)
            {
                {
                    if (i % 60 == 0)
                        printf("\n\t");
                    printf("%c", payload[i]);
                }
            }
        }

        else if (rid == 2)
        {
            printf(" (Binary Text)\n");
            for (i = 0; i < pll; i++)
            {
                if (i % 12 == 0)
                    printf("\n\t");
                printf("0x%02X ", payload[i]);
            }
            printf("\n    ");

            for (i = 0; i < pll; i++)
            {

                if (i % 50 == 0)
                    printf("\n\t");
                printf("%c", 0xAA ^ payload[i]);
            }
        }

        else
            printf(" (Unknown Text)\n");

        printf("\n    ");

        x++;
    }
    putchar('\n');
}

int ReadHeadStream(char *dst, int count, FILE *ifp)
{
    int data, i;

    for (i = 0; i < count; i++)
    {
        if ((data = fgetc(ifp)) == EOF)
            return (1);       // if line exit, return *exit code* : 1
        dst[i] = data & 0xFF; // main part of this code
    }
    return 0;
}