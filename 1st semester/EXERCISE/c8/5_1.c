#include<stdio.h>
int main(){
    printf("i\ti*i\ti*i*i\n");
    printf("-\t---\t-----\n");
    for(int i=2;i<=100;i++)
        printf("%d\t%d\t%d\n",i,i*i,i*i*i);      
}