#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x;

        printf("Enter a number: ");
        scanf("%d", &x);
        for (int i = 0; i < x; i++)
        {
            int breaker = 0;
            for (int j = i; j <= x; j++)
            {
                /* code */
                if (i * j == x)
                {
                    printf("%d and %d\n", i, j);
                    breaker = 1;
                    break;
                }
            }
        }
    }

    return 0;
}
