#include <stdio.h>
int main(void)
{
    int len, width;
    printf("Enter lenght: ");
    scanf("%d", &len);

    printf("Enter width: ");
    scanf("%d", &width);

    printf("Area is %d\n", len * width);

    return 0;
}