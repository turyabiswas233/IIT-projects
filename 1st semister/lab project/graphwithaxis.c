#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define max(x, y) x > y ? x : y
#define min(x, y) x > y ? y : x
double f(double x)
{
    return (x * x + 4 * x + 4);
}

int main(int argc, char const *argv[])
{
    /* code */
    int a = -90, b = 90;
    float domL = 0, domH = 0;

    for (float i = a; i <= b; i += 15)
    {
        float y = 20 + (10 * sin(i * PI / 180));
        domL = (float)min(domL, (y - 20) / 10);
        domH = (float)max(domH, (y - 20) / 10);
        // print x-axis values on left vertical
        printf("%10.2f -> \t", i);

        if (i == 0)
        {
            // print y-axis
            for (int j = 0; j < 2 * (int)y; j++)
            {
                /* code */
                if (j == 20)
                    printf("+");
                else if (j <= 40)
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
                printf("|"); // print (-)x-axis
            else if (j < 40)
            {
                printf(" ");
            }
            else
            {
                printf("*");
                break;
            }
        }
        printf("*");

        if ((int)y < 20)
        {
            for (int k = (int)y; k < 40; k++)
            {
                if (k < 19)
                    printf(" ");
            }

            printf("|"); // print (+)x-axis
        }
        printf("\n");
    }
    printf("\n\t#Domain: [%d,%d]\n", (int)min(a, b), (int)max(a, b));
    printf("\n\t#Range: [%0.3f,%0.3f]\n", domL, domH);
    return 0;
}
