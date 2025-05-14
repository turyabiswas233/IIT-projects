#include <iostream>
using namespace std;
void quickSort(int, int);
int partition(int, int);
void printArr(int);
int arr[] = {13, 81, 10, 43, 31, 75, 0, 92};

int count = 0;
int n = sizeof(arr) / sizeof(arr[0]);
int main()
{

    quickSort(0, n - 1);
    printArr(n);

    // cout << "TIME: " << count << endl;
    return 0;
}

void printArr(int size)
{
    cout << endl
         << "Array: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int partition(int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    int temp;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            cout << temp << ", ";
        }
        count++;
    }
    i++;
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    cout << "\n";

    return i;
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pivID = partition(low, high);
        quickSort(low, pivID - 1);
        quickSort(pivID + 1, high);
    }
}
