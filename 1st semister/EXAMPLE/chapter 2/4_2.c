#include <stdio.h>
// prime number test
int main(int argc, char const *argv[])
{
    int num, i, isPrime;
    printf("Enter a number: ");
    scanf("%d", &num);

    // now test it
    isPrime = 1;
    for (i = 2; i <= num / 2; i++)
    {
        /* code */
        if (num % i == 0)
        {
            /* code */
            isPrime = 0;
        }
    }
    if (isPrime == 1)
        printf("It is prime");
    else
        printf("It is not prime");
    return 0;
}
