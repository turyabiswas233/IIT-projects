#include <bits/stdc++.h>
using namespace std;
#define max_size 1000
int arr[max_size] = {0};
void printArr(int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertionSort(int len)
{
    for (int i = 1; i < len; i++)
    {
        int tmp = arr[i];
        int j = i - 1;
        for (; j >= 0 && arr[j] > tmp;)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = tmp;
    }
}
int main()
{
    int n;
    cout << "Enter number of elemets(n): ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    printArr(n);
    insertionSort(n);
    printArr(n);

    return 0;
}