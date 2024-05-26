#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK -1
#define inf INT_MAX

struct graph
{
    int color;
    int prev;
    int d;
} **G;

void BFS(int **m, int s, int size, struct graph **G)
{
    for (int i = 0; i < size; i++) // O(SIZE) = O(n)
    {
        G[i]->color = WHITE;
        G[i]->prev = -1;
        G[i]->d = inf;
    }
    G[s]->color = GRAY;
    G[s]->prev = -1;
    G[s]->d = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) // O(EDGES)
    {
        int u = q.front();
        q.pop();

        for (int v = size - 1; v >= 0; v--) // O(SIZE) = O(n)
        {
            if (m[u][v] == 1 && G[v]->color == WHITE)
            {
                G[v]->color = GRAY;
                G[v]->d = G[u]->d + 1;
                G[v]->prev = u;
                q.push(v);
                cout << u << "->" << v << " ";
            }
        }
        cout << endl;
        G[u]->color = BLACK;
    }

    // Total Complexity: O(SIZE + EDGE)
}

void printPath(struct graph **G, int s, int v)
{
    if (s == v)
        cout << s << endl;
    else if (G[v]->prev == -1)
        cout << "NO PATH!!\n";
    else
    {
        printPath(G, s, G[v]->prev);
        cout << v << " ";
    }
}
int main()
{
    cout << "Yahoo\n";
    int size;
    cin >> size;
    int **m;
    G = (struct graph **)malloc(size * sizeof(struct graph *));
    m = (int **)malloc(size * sizeof(int *));
    // init matrix
    for (int i = 0; i < size; i++)
    {
        m[i] = (int *)malloc(size * sizeof(int));
        G[i] = (struct graph *)malloc(sizeof(struct graph));
        for (int j = 0; j < size; j++)
        {
            m[i][j] = 0;
        }
    }

    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        m[a][b] = 1;
        m[b][a] = 1;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    int startIndex;
    cout << "Enter starting point[index number]: ";
    cin >> startIndex;
    BFS(m, startIndex, size, G);
    cout << "Enter from path[s] to path[v] [0 to " << size << "]: ";
    int v;
    cin >> startIndex >> v;
    printPath(G, startIndex, v);

    return 0;
}
/*
0 1
1 2
2 3
3 4
3 5
4 5
4 6
5 7
6 7

*/