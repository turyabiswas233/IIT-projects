#include <stdio.h>
void sum(int x,int y) {
    printf("%d",x+y);
}
int main(int argc, char const *argv[])
{
    FILE *fcp,*fco;
    fcp = fopen(argv[1],"rb");
    fco = fopen(argv[2],"wb");

    char c;
    while ((c = fgetc(fcp)) != EOF)
    {
        fputc(c,fco);
    }
    fclose(fcp);
    fclose(fco);

    return 0;
}
