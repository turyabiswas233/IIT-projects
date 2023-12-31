#include<stdio.h>
#include<stdlib.h>
int main(){
    double d;
    int i=0;
    FILE *fp1,*fp2;
    fp1=fopen("values.txt","wb");
    fp2=fopen("count.txt","wb");
    while(d!=0)
    {
        printf("enter a double number(press 0 for stop):\n");
        scanf("%lf",&d);
        fwrite(&d,sizeof d ,1,fp1);
        i++;
    }
    fwrite(&i,sizeof i,1,fp2);  
    fclose(fp1);
    fclose(fp2);    
}