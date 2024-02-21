#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    int c;
    fp = fopen("randomNum.bin", "wb");
    for (int i = 0; i < 100; i++)
    {
        c = 0xFF & rand();
        fwrite(&c, sizeof(c), 1, fp);
        printf("%d\n", c);
    }
    printf("Success\n");
    fclose(fp);

    return 0;
}
