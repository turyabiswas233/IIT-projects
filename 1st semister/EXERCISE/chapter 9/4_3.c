#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    FILE *fp1,*fp2;
    //command line error chacking 
    if(argc!=3)
    {
         printf("<source><destination>\n");
         exit(1);
    } 
    //file chack
    if((fp1=fopen(argv[1],"rb"))==NULL)
    {
          printf("cannot open file\n");
          exit(1);
    }
    fp2=fopen(argv[2],"wb");

    //copy 
    char c[100];
    while(!feof(fp1))
    {
        fgets(c,100,fp1);
        if(ferror(fp1))
        {
            printf("error reading source\n");
            exit(1);
        }
        if(!feof(fp1))   fputs(c,fp2);

        if(ferror(fp2))
        {
            printf("error writing destination\n");
        }
    }

    if(feof(fp1))   printf("read successfully\n");
    if(!ferror(fp2)) printf("write successfully\n");
    //closing error chacking
    if((fclose(fp1))==EOF)
    {
        printf("error closing source\n");
        exit(1);
    }

    if((fclose(fp2))==EOF)
    {
        printf("error closing destination\n");
        exit(1);
    }
    return 0;

}