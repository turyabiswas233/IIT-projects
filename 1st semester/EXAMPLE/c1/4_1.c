#include <stdio.h>
int main()
{
    int num;
    float f;

    // ask to get an input
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter a floating point number: ");
    scanf("%f", &f);

    // print those user input(s)
    printf("%d ", num);
    printf("%0.2f\n", f);

    return 0;
}