#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int c;
    long seek;
    fp = fopen("randomNum.bin", "rb");
    if (fp == NULL)
    {
        perror("File not found");
        exit(1);
    }
    while (1)
    {
        printf("Seek your position, Enter an integer value (-,+) ['q' to exit...]: ");
        scanf("%ld", &seek);
        if (seek == 'q')
            break;
        else
        {

            fseek(fp, (long)seek, SEEK_CUR);
            if (fread(&c, sizeof(c), 1, fp) != 1)
                break;

            printf("%d\n", c);
        }
    }

    fclose(fp);
    return 0;
}
