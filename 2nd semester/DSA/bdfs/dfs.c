#include <stdio.h>
#include <stdlib.h>

enum Color
{
    WHITE,
    GRAY,
    BLACK
};
typedef struct graph
{
    enum Color color;
    char *name;
    int prev;
    int d;
    int f;
} Graph;

int size = 0;
int **arr;
Graph **g;
int time;
void DFS(int i)
{
    if (g[i]->color == WHITE)
    {
        g[i]->color = GRAY;
        time++;
        g[i]->d = time;

        for (int k = 0; k < size; k++)
        {
            if (g[k]->color == WHITE && arr[i][k] == 1)
            {
                g[k]->prev = i;
                DFS(k);
            }
        }

        g[i]->color = BLACK;
        g[i]->f = ++time;
    }
}
void printgraph()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {

            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}
void initGraph()
{
    arr = (int **)malloc(sizeof(int *) * size);
    g = (Graph **)malloc(size * sizeof(Graph *));
    if (arr == NULL || g == NULL)
    {
        perror("Failed to init graph and matrix\n");
        exit(1);
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
        g[i] = (Graph *)malloc(sizeof(Graph));
        g[i]->name = (char *)malloc(sizeof(char) * 50);
        g[i]->color = WHITE;
        g[i]->d = -1;
        g[i]->f = -1;
        g[i]->prev = -1;
        scanf(" %s", g[i]->name);

        if (arr[i] == NULL)
        {
            perror("failed to create matrix\n");
            exit(1);
        }
        if (g[i] == NULL)
        {
            perror("failed to create graph\n");
            exit(1);
        }

        for (int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void printPath(int s, int d)
{
    if (s == d)
        printf("%s", g[s]->name);
    else if (g[d]->prev == -1)
        printf("NO PATH]\n");
    else
    {
        printPath(s, g[d]->prev);
        printf("->%s", g[d]->name);
    }
}
int main()
{
    int edges;
    scanf("%d %d", &size, &edges);
    initGraph();
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        arr[x][y] = 1;
    }
    // printgraph();
    time = 0;
    DFS(0);

    printPath(0, 3);

    return 0;
}
