#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> array;
    stack<int> lower;
    stack<int> upper;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        array.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        
    }


    while (array.empty() == false)
    {
        cout << array.back() << " ";
        array.pop_back();
    }
}

// 5+6*9-(8-5)/5