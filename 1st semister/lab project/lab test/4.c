#include <stdio.h>
int main()
{
    int x;
    printf("Enter a number:");
    scanf("%d", &x);
    if (x % 5 == 0 || x % 11 == 0)
    {
        if (x % 5 == 0 && x % 11 == 0)
        {
            printf("Both");
        }
        else if (x % 5 == 0)
        {
            printf("5 but not 11");
        }
        else
        {
            printf("11 but not 5");
        }
    }
    else
    {
        printf("NONE");
    }
    printf("\n");
    return 0;
}
