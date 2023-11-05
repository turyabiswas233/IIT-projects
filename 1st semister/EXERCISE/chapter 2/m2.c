#include <stdio.h>

int main()
{
    int test;
    printf("How many rooms in your house?? :-  ");
    scanf("%d", &test);
    float room = 1;
    for (int i = 0; i < test; i++)
    {
        /* code */
        float l, w;
        printf("\tRoom no %d\n", i + 1);
        printf("Enter length: ");
        scanf("%f", &l);
        printf("Enter width: ");
        scanf("%f", &w);

        room += w * l;
    }
    printf("Total Square of your room is: %0.2f\n", room);

    return 0;
}