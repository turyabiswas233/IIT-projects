#include <stdio.h>
#define max_size 99999

int array[max_size];
int tmpArray[max_size];
void mergesort(int left, int right);
void merge(int left, int mid, int right);
void printArray(int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", array[i]);
        if (i < n - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &array[i]);
    }
    printArray(n);
    mergesort(0, n - 1);
    printArray(n);
}
void mergesort(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(left, mid);
        mergesort(mid + 1, right);
        merge(left, mid + 1, right);
    }
}
void merge(int left, int mid, int right)
{
    int i, j, k;
    i = left;
    j = mid;
    k = left;

    int numElement = right - left + 1;
    while (i < mid && j <= right)
    {
        if (array[i] < array[j])
        {
            tmpArray[k++] = array[i++];
        }
        else
            tmpArray[k++] = array[j++];
    }

    // copy rest of the left portion of array
    while (i < mid)
    {
        tmpArray[k++] = array[i++];
    }
    // copy rest of the right portion of array
    while (j <= right)
    {
        tmpArray[k++] = array[j++];
    }

    // copy the entire temporary array in main array
    for (i = left; i < numElement; i++)
    {
        array[i] = tmpArray[i];
    }
}
