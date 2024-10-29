#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    bool visited;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->visited = false;
    return node;
}
struct graph
{
    int V;
    struct Node **adjList;
};

void dfs(struct graph *G, struct Node *u)
{
    u->visited = true;
    printf("%d ", u->data);
    for (struct Node *v = G->adjList[u->data]; v != NULL; v = v->right)
    {
        if (!v->visited)
        {
            dfs(G, v);
        }
    }
}

void init(struct graph *G, int V)
{
    G->V = V;
    G->adjList = (struct Node **)malloc(V * sizeof(struct Node *));
    for (int i = 0; i < V; i++)
    {
        G->adjList[i] = NULL;
    }
}

int main(int argc, char const *argv[])
{
    struct graph *G = (struct graph *)malloc(sizeof(struct graph));
    init(G, 5);
    G->adjList[0] = newNode(1);
    G->adjList[1] = newNode(2);
    G->adjList[2] = newNode(3);
    G->adjList[3] = newNode(4);
    G->adjList[4] = newNode(5);

    G->adjList[0]->left = G->adjList[1];
    G->adjList[0]->right = G->adjList[2];

    G->adjList[1]->left = G->adjList[3];
    G->adjList[1]->right = G->adjList[4];

    dfs(G, G->adjList[0]);

    return 0;
}
