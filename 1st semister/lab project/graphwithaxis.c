#include <stdio.h>
#include <math.h>
#define PI 3.14159
double f(double x)
{
    return sin(x);
}

int main(int argc, char const *argv[])
{
    /* code */
    int a = -90, b = 90;

    for (float i = a; i <= b; i += 15)
    {
        float y = 20 + (10 * f(i * PI / 180));

        // print x-axis values on left vertical
        printf("%0.2f -> \t", i);
        if (i == 0)
        {
            for (int j = 0; j < 2 * (int)y; j++)
            {
                /* code */
                if (j == 20)
                    printf("*");
                else if (j < 10)
                    printf(" ");
                else if (j < 30)
                    printf("-");
                else
                    break;
            }
            printf("\n");
            continue;
        }
        for (float j = 0; j < (int)y; j++)
        {
            if (j == 20)
                printf("|"); // print (-)y-axis
            else
                printf(" ");
        }

        printf("*");

        if ((int)y < 20)
        {
            while ((int)y < 19)
            {
                printf(" ");
                y++;
            }
            printf("|"); // print (+)y-axis
        }
        printf("\n");
    }

    return 0;
}
