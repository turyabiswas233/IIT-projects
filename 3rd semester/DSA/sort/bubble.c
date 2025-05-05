#include <stdio.h>
#include <stdlib.h>
int count = 0;
void bubbleSort(int *arr, int t)
{

    for (int i = 0; i < t; i++)
    {
        int swapped = 0;
        for (int j = 0; j < t; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = (1);
                count++;
            }
        if (!swapped)
            break;
    }
}
int main()
{
    int *arr;
    int n, t;

    scanf("%d", &t);

    while (t--)
    {

        scanf(" %d", &n);
        arr = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            // arr[i] = (int)malloc(sizeof(int));
            scanf(" %d", &arr[i]);
        }
        count = 0;
        bubbleSort(arr, n - 1);
        printf("TIME for random data[%d]:\t%6d\n", n, count);
        count = 0;
        bubbleSort(arr, n - 1);
        printf("TIME for best-case data[%d]:\t%6d\n", n, count);
    }

    return 0;
}