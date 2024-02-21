#include <stdio.h>
int main(int argc, char const *argv[])
{
    float num;
    int choise;
    printf("1. feet to metes, 2: meters to feet.\n");
    printf("Enter choice: ");
    scanf("%d", &choise);

    if (choise == 1)
    {
        printf("Enter number of feet: ");
        scanf("%f", &num);
        printf("Meters : %f\n", num / 3.28);
    }
    else
    {
        printf("Enter number of Meters: ");
        scanf("%f", &num);
        printf("Feet : %f\n", num * 3.28);
    }
    return 0;
}
