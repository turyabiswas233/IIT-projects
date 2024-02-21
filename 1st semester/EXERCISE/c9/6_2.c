#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int ck = 1;
    FILE *fp;
    if ((fp = fopen(argv[1], "rb")) == NULL)
        ck = 0;
    if (ck == 1)
    {
        printf("location of the file: %p\n", fp);
        fseek(fp, 0L, SEEK_END);
        long l = ftell(fp);
        printf("bytes of the file: %ld", l);
    }
    fclose(fp);
}