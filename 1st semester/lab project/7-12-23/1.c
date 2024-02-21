#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void ReadCharStream(char *dst, int count, FILE *ifp);

int main()
{
    uint16_t i = 0, rid, pll;
    unsigned char payload[2048];
    FILE *fp;

    if ((fp = fopen("file.dat", "rb")) == NULL)
    {
        exit(1);
    }
    int x = 1;
    while (1)
    {
        ReadCharStream(payload, 4, fp);

        rid = payload[1] * 256 + payload[0];
        pll = payload[3] * 256 + payload[2];

        // printf("\n\nrid=%d, pll=%d\n", rid, pll);

        ReadCharStream(payload, pll, fp);

        printf("\n\nRecord no. %03d:\n  RID: 0x%03X", x, rid);

        if (rid == 1)
            printf(" (ASCII Text)");
        else if (rid == 2)
            printf(" (Binary Text)");
        else
            printf(" (Unknown Text)");
        for (i = 0; i < pll; i++)
        {
            if (rid == 1)
            {
                if (i % 50 == 0)
                    printf("\n    ");
                printf("%c", payload[i]);
            }
            else if (rid == 2)
            {
                if (i % 12 == 0)
                    printf("\n    ");
                printf("0x%02X ", payload[i]);
            }
        }
        printf("\n    ");

        x++;
    }
    putchar('\n');
}

void ReadCharStream(char *dst, int count, FILE *ifp)
{
    int data, i;
    for (i = 0; i < count; i++)
    {
        if ((data = fgetc(ifp)) == EOF)
            exit(1);
        dst[i] = data & 0xFF;
    }
}