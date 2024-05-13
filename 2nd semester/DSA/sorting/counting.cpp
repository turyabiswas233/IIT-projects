#include <bits/stdc++.h>
using namespace std;
void delay(int);
void getMax(int *, int, int *);
void getMin(int *, int, int *);
void setCounters(int *, int *, int);
void printArr(int *, int, int);
void setZero(int *, int, int);
void printTitle(string);

void countingSort(int *, int);

int main()
{
    int maxVal, minVal, len;

    printTitle("####\tWelcome to Counting Sort\t####\nEnter Lenght: ");
    cin >> len;
    int arr[len];
    cout << "Enter elements (" << len << "): ";
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    printArr(arr, 0, len - 1); // initial array
    countingSort(arr, len);
    printArr(arr, 0, len - 1); // output array

    return 0;
}
void delay(int time)
{
    while (time--)
    {
        for (size_t i = 0; i < 1000 * 1000; i++)
        {
            i = i;
        }
    }
}
void getMin(int *arr, int len, int *minVal)
{
    *minVal = arr[0];
    for (int i = 1; i < len; i++)
    {
        *minVal = min(*minVal, arr[i]);
    }
}
void getMax(int *arr, int len, int *maxVal)
{
    *maxVal = arr[0];
    for (int i = 1; i < len; i++)
    {
        *maxVal = max(*maxVal, arr[i]);
    }
}
void setCounters(int *arr1, int *arr2, int len)
{
    for (int i = 0; i < len; i++)
    {
        ++arr2[arr1[i]];
    }
}
void setZero(int *arr, int minV, int maxV)
{
    for (int i = minV; i <= maxV; i++)
    {
        arr[i] = 0;
    }
}
void printArr(int *arr, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        delay(50);
        cout << arr[i] << " ";
    }
    cout << endl;
}
void printTitle(string s)
{
    delay(50);
    for (auto i : s)
    {
        cout << i;
    }
}

void countingSort(int *arr, int len)
{
    int maxVal, minVal, output[len];
    getMax(arr, len, &maxVal);
    getMin(arr, len, &minVal);
    int counters[maxVal + 2] = {0};
    setZero(counters, minVal, maxVal);
    setCounters(arr, counters, len);
    for (int i = minVal; i <= maxVal; i++)
    {
        counters[i] = counters[i] + counters[i - 1];
    }

    // finally set data into output as sorted array
    for (int i = len - 1; i > -1; i--)
    {

        output[counters[arr[i]]] = arr[i];
        --counters[arr[i]];
    }

    for (int i = 0; i < len; i++)
    {
        arr[i] = output[i + 1];
    }
}