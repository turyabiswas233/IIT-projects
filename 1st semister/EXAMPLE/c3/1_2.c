#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b;
    char ch;

    printf("Do you want to :  \n");
    printf("Add, Subtract, Multiply, or Divide?\n");
    printf("Enter first letter: ");
    ch = getchar();
    printf("\n");

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    if (ch == 'A')
        printf("%d", a + b);
    if (ch == 'S')
        printf("%d", a - b);
    if (ch == 'M')
        printf("%d", a * b);
    if (ch == 'D')
        printf("%d", a / b);

    return 0;
}
