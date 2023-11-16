#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    int flag = 0;
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        printf("It is not prime\n");
    else
        printf("It is prime\n");

    return 0;
}
