#include <stdio.h>
void checkEvenOdd(int x);

int main()
{
        int x;
        printf("Enter an integer: ");
        scanf("%d", &x);

        checkEvenOdd(x);
}

void checkEvenOdd(int x)
{
        if (x % 2 == 0)
        {
                printf("It is EVEN\n");
        }
        else
        {
                printf("It is ODD\n");
        }
}