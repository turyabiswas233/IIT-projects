#include<stdio.h>
#include<stdlib.h>
int main(){
    char fnm[100];
    printf("enter the file name to erase:\n");
    fgets(fnm,sizeof fnm,stdin);
    printf("are you sure to remove file\n\tY or N\n");
    if(getchar()=='Y')
        remove(fnm);
    return 0;

}