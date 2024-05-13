#include <bits/stdc++.h>

using namespace std;
vector<int> duplicates(long long arr[], int n)
{
    vector<int> res;
    sort(arr, &arr[n]);
    long long temp = arr[n - 1];

    for (int i = 0; i < n; i++)
    {

        if (arr[i - 1] == arr[i])
        {
            if (temp == arr[i])
                continue;
            temp = arr[i];
            res.push_back(temp);
        }
    }
    if (res.size() == 0)
    {
        cout << -1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    long long arr[] = {2, 0, 3, 3, 2};

    vector<int> ans;
    int len = sizeof(arr) / sizeof(arr[0]);
    ans = duplicates(arr, len);

    for (int i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
