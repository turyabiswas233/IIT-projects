#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    if(argc!=2)
    {
        printf("<file name>\n");
        exit(1);
    }
    long l;
    FILE *fp;
    if((fp=fopen(argv[1],"rb"))==NULL)
    {
        printf("cannot open file\n");
        exit(1);
    }
    printf("enter byte to seek to:");
    scanf("%ld",&l);
    if(fseek(fp,l,SEEK_SET))
    {
        printf("error\n");
        exit(1);
    }
    printf("value at %ld is %d",l,fgetc(fp));
    fclose(fp);
}