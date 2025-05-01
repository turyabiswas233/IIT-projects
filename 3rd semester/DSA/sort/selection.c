#include <stdio.h>
#include <stdlib.h>
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void printArr(int *arr, int n)
{
    if (n > 0)
    {
        printArr(arr, n - 1);
        printf("%d ", arr[n - 1]);
    }
    return;
}
int main()
{
    int *arr;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
    }

    arr = (int *)malloc(sizeof(int) * n);
    selectionSort(arr, n);
    printArr(arr, n);
    return 0;
}
// 3 4 5 6 5 4