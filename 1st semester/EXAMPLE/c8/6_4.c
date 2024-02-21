#include<stdio.h>
int main (void)
{
    int i ,j;
    char op;
    printf("Enter two number & operation:");
    scanf("%d %d %c", &i, &j,&op);
    switch(op)
    {
        case '+' : printf("%d", i+j);
                break;
        case '-' : printf("%d", i-j);
                break;
        case '/' : if(j) printf("%d", i/j);
                break;
        case '*' : printf("%d" , j*j);
                break;
    }
    return 0;
}