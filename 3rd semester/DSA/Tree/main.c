#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *p;
};
void printHeap(int *arr)
{
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int *arr, int n, int i)
{
    int maxId = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[maxId])
        maxId = l;
    if (r < n && arr[r] > arr[maxId])
        maxId = r;

    if (maxId != i)
    {
        swap(arr[i], arr[maxId]);
        heapify(arr, n, maxId);
    }
}
void heapsort(int *arr)
{
     int n =(int) sizeof(arr) / sizeof(arr[0]);

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    heapsort(arr);
    printHeap(arr);
    return 0;
}
