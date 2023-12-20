#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct f_packet
{
    uint32_t fd1;
    uint16_t fd2;
    uint8_t fd3;
};
union read_rs
{
    struct f_packet bits;
    unsigned char str[8];
} rd;
bool read_file_system(unsigned char *p, FILE *fp);
int main()
{
    FILE *fp;

    fp = fopen("DataFile.bin", "rb");
    if (fp == NULL)
    {
        perror("File not found\n");
        exit(1);
    }
    unsigned short counter = 1;
    while (1)
    {
        if (read_file_system(rd.str, fp))
        {

            printf("\nRecord no. %03d:", counter++);
            printf("\n\tField1: 0x%08x", rd.bits.fd1);
            printf("\n\tField1: 0x%04x", rd.bits.fd2);
            printf("\n\tField1: 0x%02x", rd.bits.fd3);
        }
        else
        {
            break;
        }
        putchar('\n');
    }

    fclose(fp);
    return 0;
}
bool read_file_system(unsigned char *p, FILE *fp)
{

    if (fread(p, sizeof(p), 1, fp) != 1)
    {
        return false;
    }

    return true;
}