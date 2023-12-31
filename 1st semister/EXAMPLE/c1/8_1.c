#include <stdio.h>
int get_sqr(void);

int main()
{
    int sqr = get_sqr();
    printf("Square is : %d\n", sqr);
}

int get_sqr(void)
{
    int num = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    return num * num;
}