// area calculator
#include <stdio.h>
void printArea(int x);
int main(int argc, char const *argv[])
{
    int x;
    printf("# Choose an option:\n");
    printf("\t(1) -> Circle\n");
    printf("\t(2) -> Triangle\n");
    printf("\t(3) -> Rectangle\n");
    scanf("%d", &x);
    printArea(x);
    return 0;
}
void printArea(int x)
{
    int r, b, h, l, w;
    switch (x)
    {
    case 1:
        printf("Enter radius: ");
        scanf("%d", &r);
        printf("Area of Circle is %0.3f", 3.14156 * r * r);
        break;
    case 2:
        printf("Enter base & height: ");
        scanf("%d%d", &b, &h);
        printf("Area of Triangle is %0.3f", 0.5 * h * b);
        break;
    case 3:
        printf("Enter lenght and width: ");
        scanf("%d%d", &l, &w);
        printf("Area of Rectangle is %0.3f", 1.0 * l * w);
        break;
    default:
        break;
    }
}