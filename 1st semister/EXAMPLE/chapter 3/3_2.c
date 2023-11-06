#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);

    for (; i; i--)
        printf("%d ", i);

    return 0;
}
