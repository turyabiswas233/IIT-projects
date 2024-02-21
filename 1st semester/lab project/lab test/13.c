#include <stdio.h>
long long factorial(long long n);
void main()
{
    int n;
    printf("Enter a number(0<= n <= 20): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Factor of %d = %lld\n", i, factorial((long long)i));
    }
}
long long factorial(long long n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}