#include <stdio.h>
int main(int argc, char const *argv[])
{
    int x;
    scanf("%d", &x);
    int y = 0;
    int tempx = x;
    int thous = 1;
    while (tempx > 10)
    {
        thous *= 10;
        tempx /= 10;
    }

    for (; x > 0;)
    {
        int temp = x % 10;
        y += thous * temp;
        thous /= 10;
        x /= 10;
    }
    printf("%d", y);

    return 0;
}
