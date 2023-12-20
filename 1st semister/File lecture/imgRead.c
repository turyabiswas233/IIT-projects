#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *img;
    img = fopen("img_rt.jpg", "rb");
    char ul[8];
    if (img = NULL)
    {
        printf("Cannot find image file\n");
        exit(1);
    }
    while (!feof(img))
    {
        if (fread(ul, 8, 1, img) == 1)
        {
            for (int i = 0; i < 8; i++)
                printf("0x%08x ", ul[i]);
            printf("\n");
        }
    }

    fclose(img);
    return 0;
}
