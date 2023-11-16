#include <stdio.h>
int formula(int x)
{
    return 4 * x + 1;
}
int main()
{
    int x;
    scanf("%d", &x);

    for (int i = 0; i < x; i++)
    {
        printf("%d%c ", formula(i), i < x - 1 ? ',' : '\n');
    }

    return 0;
}
