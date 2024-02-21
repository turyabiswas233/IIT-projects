#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    vector<int> v = {11,2,3,4,5,6};
    sort(v.begin(), v.end());
    for (int i = 0; i < 6; i++)
    {
        /* code */
        cout << v[i]<< " " ;
    }
    
    return 0;
}
