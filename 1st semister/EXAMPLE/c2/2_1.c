#include <stdio.h>
int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    if (num < 0)
        printf("Number is negative");
    else
        printf("Number is non-negative");
}