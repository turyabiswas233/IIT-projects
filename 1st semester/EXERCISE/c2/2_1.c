#include <stdio.h>
void result(int num1, int num2);
void sum(int x, int y);
void prod(int x, int y);

int main()
{
        int x, y, option;
        printf("Enter two numbers: ");
        scanf("%d%d", &x, &y);

        result(x, y);
}

void result(int num1, int num2)
{
        int option;
        printf("\n\t\tPlease choose one of the two options\t\t\n");
        printf("\t (1) - SUM\n");
        printf("\t (2) - PRODUCT\n");
        printf("\t [type 1 or 2 ] :-  ");

        scanf("%d", &option);
        if (option == 1)
        {
                sum(num1, num2);
        }
        else if (option == 2)
        {
                prod(num1, num2);
        }
        else
        {
                printf("##\tInvalid option\t##\n");
                result(num1, num2);
        }
}

void sum(int x, int y)
{
        printf("SUM = %d\n", x + y);
}
void prod(int x, int y)
{
        printf("PRODUCT = %d\n", x * y);
}