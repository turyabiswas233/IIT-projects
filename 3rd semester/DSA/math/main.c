#include <stdio.h>
float f(float x, float y)
{
    return x - y;
}
int main(int argc, char const *argv[])
{

    float x, x0, y0, k[4], h;
    int i, n;
    printf("Enter x,x0,y0,h: ");
    scanf("%f%f%f%f", &x, &x0, &y0, &h);

    n = (x - x0) / h;

    for (i = 1; i <= n; i++)
    {
        k[0] = h * f(x0, y0);
        k[1] = h * f(x0 + 1 / 2 * h, y0 + 1 / 2 * k[0]);
        k[2] = h * f(x0 + 1 / 2 * h, y0 + 1 / 2 * k[1]);
        k[3] = h * f(x0 + h, y0 + k[2]);

        y0 += 1.0 / 6 * (k[0] + 2 * k[1] + 2 * k[2] + k[3]);
        x0 += h * 1.0;
        printf("\t%f\t%f\n", x0, y0);
    }

    return 0;
}
// 100 0.5 15 1.5