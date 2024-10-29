#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

struct graph
{
    int V;
    int E;
    int **Adj;
};

struct graph *adjMatrixOfGraph()
{
    int u, v;
    struct graph *G = (struct graph *)malloc(sizeof(struct graph));
    if (!G)
    {
        printf("Memory Error\n");
        return NULL;
    }
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &G->V, &G->E);
    G->Adj = (int **)malloc(sizeof(int *) * G->V);
    for (int i = 0; i < G->V; i++)
    {
        G->Adj[i] = (int *)malloc(sizeof(int) * G->V);
        for (int j = 0; j < G->V; j++)
        {
            G->Adj[i][j] = 0;
        }
    }
    for (int i = 0; i < G->E; i++)
    {
        printf("Enter the edge (u, v): ");
        scanf("%d %d", &u, &v);
        G->Adj[u][v] = 1;
        G->Adj[v][u] = 1;
    }
    return G;
}

void bfs(struct graph *G, int start)
{
    int queue[MAX], front = 0, rear = 0, v;
    bool visited[G->V];
    for (int i = 0; i < G->V; i++)
    {
        visited[i] = false;
    }
    visited[start] = true;
    queue[rear++] = start;
    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < G->V; i++)
        {
            if (G->Adj[v][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

void printPath(int *parent, int start, int end)
{
    if (start == end)
    {
        printf("%d ", start);
    }
    else if (parent[end] == -1)
    {
        printf("No path\n");
    }
    else
    {
        printPath(parent, start, parent[end]);
        printf("%d ", end);
    }
}

int main(int argc, char const *argv[])
{
    struct graph *G = adjMatrixOfGraph();
    for (int i = 0; i < G->V; i++)
    {
        for (int j = 0; j < G->V; j++)
        {
            printf("%d ", G->Adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}
