#include <stdio.h>

int n, root_size;
void heapsort(int[]);
void swap(int *, int *);
void buildMaxHeap(int[]);
void heapify(int[], int);
void printArr(int[], int);

int main(int argc, char const *argv[])
{
    int arr[6] = {2, 8, 5, 3, 9, 1};
    root_size = n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr);
    printArr(arr, root_size);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapsort(int arr[])
{
    buildMaxHeap(arr);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        n = n - 1;
        heapify(arr, 1);
    }
}

void buildMaxHeap(int arr[])
{
    n = root_size;
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, i);
    }
}
void heapify(int arr[], int i)
{
    int max;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n - 1 && arr[left] > arr[i])
        max = left;
    else
        max = i;

    if (right <= n - 1 && arr[right] > arr[max])
        max = right;

    if (max != i)
    {
        swap(&arr[i], &arr[max]);
        heapify(arr, max);
    }
}

void printArr(int arr[], int t)
{
    if (t > 0)
    {
        printArr(arr, --t);
        printf("[%d]:%d ", t, arr[t]);
    }
}
