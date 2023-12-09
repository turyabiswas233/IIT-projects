#include <stdio.h>
int ReadHeadStream(char *payload, int len, FILE *fp)
{
    char data;
    // rid value
    for (int i = 0; i < len; i++)
    {

        data = fgetc(fp);
        if (data == EOF)
        {
            return 1;
        }
        payload[i] = data & 0xFF;
    }
    return 0;
}
int main()
{
    int rid, pll;
    unsigned int count = 1;
    unsigned char payload[1024 * 2];
    FILE *fp;

    fp = fopen("D_File.dat", "rb");

    while (1)
    {

        if (ReadHeadStream(payload, 4, fp) == 1)
        {
            printf("Total Records: %d\n\n", count - 1);
            return 0;
        }
        else
        {

            rid = payload[0] + payload[1];
            pll = payload[2] + payload[3];
            if (ReadHeadStream(payload, pll, fp) == 1)
            {
                return 0;
            }
            printf("Record no. %03d:\n", count);

            if (rid == 1)
            {
                printf("  RID: 0x%04X (ASCII Text)\n    ", rid);
                for (int i = 0; i < pll; i++)
                {
                    if (i % 50 == 0)
                        printf("\n    ");
                    printf("%c", payload[i]);
                }
            }
            else if (rid == 2)
            {
                printf("  RID: 0x%04X (Binary Data)\n    ", rid);
                for (int i = 0; i < pll; i++)
                {
                    if (i % 16 == 0)
                        printf("\n    ");
                    printf("0x%02X ", payload[i]); // 0x0F, 0x5C
                }
            }
            else
            {
                printf("RID: 0x%04X (Unknown Data)\n", rid);
            }
        }
        count++;
        printf("\n\n");
    }

    return 0;
}
