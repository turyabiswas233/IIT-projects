#include<stdio.h>
#include<stdlib.h>
 int main(int argc,char *argv[]){
    if(argc!=2)
    {
        printf("<file name>\n");
        exit(1);
    }
    FILE *fp;
    if((fp=fopen(argv[1],"rb"))==NULL)
    {
        printf("reading error\n");
        exit(1);
    }
    fseek(fp,0L,SEEK_END);
    long l=ftell(fp);
    char ch;
    fseek(fp,0L,SEEK_SET);
    while(l--)
    {
        /* code */
        ch=fgetc(fp);
        printf("%c",ch);
    }
    fclose(fp);    
}