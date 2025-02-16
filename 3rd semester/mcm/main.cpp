#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> m(100, vector<int>(100, -1));

int RMC(vector<int> p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    m[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int q = RMC(p, i, k) + RMC(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (q < m[i][j])
        {
            m[i][j] = q;
        }
    }
    return m[i][j];
}
int main()
{

    vector<int> p;
    p = {4, 2, 3, 1, 3};
    for (int i = 1; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            cout << RMC(p, i, j) << endl;
        }
        cout << endl;
    }

    return 0;
}
