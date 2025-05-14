#include <stdio.h>
#include <stdlib.h>

int n = 0;

void printArr(int arr[], int n)
{
    if (n > 0)
    {
        printArr(arr, n - 1);
        printf("%d ", arr[n - 1]);
    }
}
void merge(int arr[], int left, int mid, int right)
{
    int *L, *R;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    L = (int *)malloc(sizeof(int) * (n1));
    R = (int *)malloc(sizeof(int) * (n2));
    int i, j;
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    i = j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy rest of the element
    // printf("\tREST: ");
    while (i < n1)
    {
        arr[k] = L[i];
        i += 1;
        k += 1;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j += 1;
        k += 1;
    }
    printArr(L, n1);
    printArr(R, n2);
    free(L);
    free(R);
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // sort each adj array element
        merge(arr, left, mid, right);
        printf("\n");
    }
}

int main()
{
    int arr[] = {25, 16, 44, 32, 12, 6, 4, 26, 32, 30};
    n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    printArr(arr, n);
    return 0;
}