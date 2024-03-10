#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 9999
int a[MAX_SIZE];
void quicksort(int p, int r);
int partition(int p, int r);
void swap_two(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
void print(int *a, int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{

    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " integer numbers using [space] separator: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
    }

    quicksort(0, n - 1);
    print(a, n);
    return 0;
}

void quicksort(int p, int r)
{
    if (p < r)
    {
        int q = partition(p, r);
        quicksort(p, q - 1);
        quicksort(q + 1, r);
    }
}
int partition(int p, int r)
{
    int x = a[r];  // x= a[r]
    int i = p - 1; // i = p-1

    for (int j = p; j <= r - 1; j++) // j = p -> r -1
    {
        if (a[j] <= x) // a[j] <= x
        {
            i += 1;                 // increase position of swapable value's index i=i+1
            swap_two(&a[i], &a[j]); // exchange a[i] with a[j]
        }
    }
    swap_two(&a[i + 1], &a[r]); // exchange a[i+1] with a[r]

    return i + 1; // send {i+1} as int
}