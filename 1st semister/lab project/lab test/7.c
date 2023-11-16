#include <stdio.h>
void printEvenSum(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        /* code */
        if (i % 2 == 0)
            sum += i;
    }
    printf("Sum of %d's even number is: %d\n", n, sum);
}
int main()
{
    printEvenSum(100);

    return 0;
}
