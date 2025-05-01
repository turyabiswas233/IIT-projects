#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 2;
bool v[N];
vector<int> adj[N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        v[i] = false;
    }
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;

    q.push(1);
    v[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << endl;

        vector<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!v[*it])
            {
                v[*it] = true;
                q.push(*it);
            }
        }
    }
    return 0;
}