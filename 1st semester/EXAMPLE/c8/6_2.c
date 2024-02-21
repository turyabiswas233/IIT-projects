#include<stdio.h>
int main(){
    char str[100];
    printf("enter letters, anything else to stop\n");
    scanf("%[a-z A-Z]",str);
    printf(str);
}