#include<stdio.h>
int main()
{
    char str[100];
    double d;
    int i,n;
    scanf("%s %f %d %n",str,&d,&i,&n);
    printf("number of characters read:%d",n);
    return 0;
}
