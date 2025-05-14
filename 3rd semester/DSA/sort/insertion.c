#include <stdio.h>
#include <stdlib.h>

void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int insert = i;
        int curVal = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > curVal)
            {
                arr[j + 1] = arr[j];
                insert = j;
            }
            else
                break;
        }
        arr[insert] = curVal;
    }
}
void printArr(int *arr, int n)
{
    if (n > 0)
    {
        printArr(arr, n - 1);
        printf("%d ", arr[n - 1]);
    }
}
int main(int argc, char const *argv[])
{

    int arr[10] = {49, 46, 42, 26, 24, 23, 12, 12, 11, 1};
    int n = 10;

    insertion(arr, n);
    printArr(arr, n);
    return 0;
}
