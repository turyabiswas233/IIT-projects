#include <stdio.h>
int main()
{
    int arr[10];
    int min;
    int max;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        if (i == 0)
        {
            min = arr[i];
            min = arr[i];
        }
        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
