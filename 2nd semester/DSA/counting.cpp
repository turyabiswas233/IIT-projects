#include <bits/stdc++.h>
using namespace std;
void printArr(int arr[], int size)
{
    for (int x = 0; x < size; x++)
    {
        cout << arr[x] << ", ";
    }
    cout << endl;
}

void countingSort(int arr[], int size)
{
    int maxV = arr[0];
    for (int i = 0; i < size; i++)
    {
        maxV = max(maxV, arr[i]); // get max value from the array
    }

    int count[maxV + 1] = {0}; // set all the counter of each element equals to 0

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++; // increase each value if position == [array's element]
    }

    // now run a loop to get cummulative sum of the array
    for (int i = 1; i < maxV + 1; i++)
    {
        count[i] += count[i - 1];
    }

    int finalArray[size] = {0};

    for (int i = size - 1; i >= 0; i--)
    {
        finalArray[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = finalArray[i];
    }

    printf("%p\n", arr);
    printf("%p\n", finalArray);
}
int main()
{
    int arr[] = {1, 9, 4, 25}; // initialize array [length = size]
    countingSort(arr, sizeof(arr) / sizeof(arr[0]));
    printArr(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}