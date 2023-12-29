#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    int i;
    printf("enter a string:\n");
    fgets(str,100,stdin);
    i=strlen(str)-1;
    if(str[i]=='\n')    str[i]='\0';
    printf("this is your string: %s",str);
    return 0;
}