#include <stdio.h>
int main(int argc, char const *argv[])
{
    char x;
    for (int i = 1; i <= 1000; i++)
    {
        printf("$%4d:\t", i);
        for (int j = 10; j <= 20; j += 5)
        {
            /* code */
            printf("%0.2f\t", i * j / 100.0);
        }
        printf("\n\n");
        printf("#Would you like to continue?(y/n): ");
        scanf("%c", &x);
        if (x == 'n')
            break;
    }

    return 0;
}
