
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j;
    printf("Enter first number: ");
    scanf("%d", &i);
    printf("Enter second number: ");
    scanf(" %d", &j);
    /* relational operations */
    printf("i < j %d\n", i < j);
    printf("i <= j %d\n", i <= j);
    printf("i == j %d\n", i == j);
    printf("i > j %d\n", i > j);
    printf("i >= j %d\n", i >= j);
    /* logical operations */
    printf("i && j %d\n", i && j);
    printf("i || j %d\n", i || j);
    printf("!i !j %d %d\n", !i, !j);
    return 0;
}
