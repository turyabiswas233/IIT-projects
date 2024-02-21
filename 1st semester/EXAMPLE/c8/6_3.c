#include<stdio.h>
int main(){
    char str[100];
    printf("enter letters and spaces\n");
    scanf("%[a-z A-Z]",str);
    printf(str);
}