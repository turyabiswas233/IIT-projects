#include<stdio.h>
#include<stdlib.h>
int main(){
    if(rename("yourfilr.txt","myfile.txt"))
        printf("failed\n");
    else    printf("successful\n");
}