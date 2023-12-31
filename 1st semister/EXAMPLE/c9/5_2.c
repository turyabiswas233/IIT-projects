#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;
    float sa[10]={3.44,34.53,12,10,13,23.43,45.65,90,23,100};
    //write
    fp=fopen("myfile.txt","wb");
    if((fwrite(sa,sizeof sa,1,fp))!=1)
    {
        printf("writing error\n");
        exit(1);
    }
    
    fclose(fp);
    //read
    if((fp=fopen("myfile.txt","rb"))==NULL)
    {
        printf("cannot open file\n");
        exit(1);
    }
    
    if((fread(sa,sizeof sa,1,fp))!=1)
    {
        printf("reading error\n");
        exit(1);
    }
    printf(sa);
    
    fclose(fp);
    
}