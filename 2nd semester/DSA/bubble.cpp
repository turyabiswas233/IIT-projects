#include <bits/stdc++.h>
using namespace std;
#define max_size 1000
int arr[max_size];
void printArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    int len = n;
    printArr(arr, len);

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            int tmp = max(arr[j], arr[i]);
            if (tmp == arr[i])
            {
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    printArr(arr, len);

    return 0;
}