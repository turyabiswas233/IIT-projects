#include<stdio.h>
#include<stdlib.h>
int main(int argC,char *argV[]){
    FILE *fp;
    char c;
    if(argC!=3){
        printf("find file name");
        exit(1);
    }
    fp=fopen(argV[1],"r");
    if(fp==NULL)
    {
        printf("cannot open file");
        exit(1);
    }
    int j=0;
    while(c!=EOF)
    {
        c=fgetc(fp);
        if(c==*argV[2]){
            j++;
        }
    }
    printf("%c is founded %d times in %s",*argV[2],j,argV[1]);
    fclose(fp);
    return 0;
}

//kahini ki holo?amio vbtasi bujsi aita 1st ta file nm 2nd ta char qus ase boi e
// dhur aita to hoise boi theke deksilm na seta na, ami bash open krtesi :)