#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
#define inf 100000

enum COLOR
{
    WHITE,
    GRAY,
    BLACK
};

typedef struct graph
{
    int d;
    int f;
    enum COLOR visited;
    int prev;
} Graph;

int time = 0;
Graph **data;
int **arr;
void DFS_VISIT(int u)
{
    data[u]->visited = GRAY;
    time += 1;
    data[u]->d = time;
    printf("%d->", time);

    for (int v = 0; v < SIZE; v++)
    {
        if (data[u]->visited == WHITE && arr[u][v] == 1)
        {
            data[v]->prev = u;
            DFS_VISIT(v);
        }
    }
    data[u]->visited = BLACK;
    time += 1;
    printf("%d->", time);
    data[u]->f = time;
    // printf("%d: %d, %d\n", u + 1, data[u]->d, data[u]->f);
}

void DFS()
{
    // now start traversing the graph
    time = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (data[i]->visited == WHITE)
            DFS_VISIT(i);
    }
}

void init()
{
    data = (Graph **)malloc(sizeof(Graph *) * SIZE);
    arr = (int **)malloc(sizeof(int *) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        data[i] = (struct graph *)malloc(sizeof(Graph) * SIZE);
        data[i]->visited = WHITE;
        data[i]->d = data[i]->f = (int)inf;
        data[i]->prev = -1;

        arr[i] = (int *)malloc(sizeof(int) * SIZE);
        for (int j = 0; j < SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }
}
int main(int argc, char const *argv[])
{
    init();
    int edge;
    scanf("%d", &edge);
    printf("enter edges from 0 to %d: ", SIZE - 1);
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        arr[u - 1][v - 1] = arr[v - 1][u - 1] = 1;
    }

    DFS();

    return 0;
}
