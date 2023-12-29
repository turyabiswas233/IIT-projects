#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;
    float sa[10]={3.44,34.53,12,10,13,23.43,45.65,90,23,100};
    int i;
    //write
    fp=fopen("myfile.txt","wb");
    for(i=0;i<10;i++)
    {
        //sa[i]=(i+1)*5.2;
        if((fwrite(&sa[i],sizeof(float),1,fp))!=1)
        {
            printf("writing error\n");
            exit(1);
        }
    }
    fclose(fp);
    //read
    if((fp=fopen("myfile.txt","rb"))==NULL)
    {
        printf("cannot open file\n");
        exit(1);
    }
    for(i=0;i<10;i++)
    {
        if((fread(&sa[i],sizeof(float),1,fp))!=1)
        {
            printf("reading error\n");
            exit(1);
        }
        printf("%f ",sa[i]);
    }
    fclose(fp);
    
}