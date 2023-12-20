#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int c;
    fp = fopen("randomNum.bin", "rb");
    for (int i = 0; i < 100; i++)
    {
        fread(&c, sizeof(c), 1, fp);
        c = c & 0xffffff;
        printf("0x%02X = %d\n", c, c);
    }
    fclose(fp);

    return 0;
}
