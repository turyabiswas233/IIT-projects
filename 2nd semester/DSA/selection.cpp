#include <bits/stdc++.h>
using namespace std;
#define max_size 1000
int arr[max_size] = {0};
void selectSort(int length);
void printArr(int n)
{
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
}
void addElements(int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    addElements(n);
    selectSort(n);
    printArr(n);

    return 0;
}
void selectSort(int length)
{
    for (int i = 0; i < length; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}