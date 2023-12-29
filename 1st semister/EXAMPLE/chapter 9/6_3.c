#include<stdio.h>
#include<stdlib.h>
 int main(){
    double d[10]={10,20,30,40,50,60,70,80,90,100};
    FILE *fp;
    long l;
    double v;
    //write
    fp=fopen("myfile.bin","wb");
    if(fwrite(d,sizeof d,1,fp) !=1)
    {
        printf("writing error\n");
        exit(1);
    }
    fclose(fp);
    //read & print
    printf("enter the element(0-9):");
    scanf("%ld",&l);
    fp=fopen("myfile.bin","rb");
    if(fseek(fp,l*sizeof(double),SEEK_SET))
    {
        printf("error\n");
        exit(1);
    }
    if(fread(&v,sizeof(double),1,fp) !=1)
    {
        printf("reading error\n");
        exit(1);
    }
    printf("element %ld is %lf",l,v);
    fclose(fp);
 }