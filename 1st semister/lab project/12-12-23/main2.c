#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
struct f_packet
{
    uint32_t fld1; // 4 byte
    uint16_t fld2; // 2 byte
    uint8_t fld3;  // 1 byte
};
union read_rs
{
    struct f_packet fpkt;
    unsigned char data[8];
} rrs;

int main(int argc, char const *argv[])
{
    FILE *fp;

    fp = fopen(argv[1], "rb");

    if (fp == NULL)
    {
        perror("File not found!!\n");
        exit(1);
    }

    int ct = 1;
    while (1)
    {
        if (fread(rrs.data, sizeof(rrs.data), 1, fp) != 1)
            break;
        else
        {

            printf("\nRecord No. %03d:", ct++);
            printf("\n\tField1: 0x%08X", rrs.fpkt.fld1);
            printf("\n\tField2: 0x%04X", rrs.fpkt.fld2);
            printf("\n\tField3: 0x%02X", rrs.fpkt.fld3);
        }
    }

    fclose(fp);
    return 0;
}