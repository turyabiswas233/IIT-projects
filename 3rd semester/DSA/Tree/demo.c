#include <stdio.h>
#include <stdlib.h>

#define inf -1000000
enum Color
{
    WHITE,
    GREY,
    BLACK
};

typedef struct graph
{
    enum Color color;
    int prev;
    int d;
    int f;

} Graph;

int size;
Graph **gp;
int **arr;
int time;
void DFS_Visit(int i)
{
    gp[i]->color = GREY;
    time++;
    gp[i]->d = time;
    for (int j = 0; j < size; j++)
    {
        if (gp[j]->color == WHITE && arr[i][j] == 1)
        {
            gp[j]->prev = i;
            DFS_Visit(j);
        }
    }
    gp[i]->color = BLACK;
    printf("%c\n", (char)(65 + i));
    time++;
    gp[i]->f = time;
}
void DFS()
{

    time = 0;
    for (int i = 0; i < size; i++)
    {
        if (gp[i]->color == WHITE)
            DFS_Visit(i);
        printf("%d: \t%d\t%d\n", (char)(i + 65), gp[i]->d, gp[i]->f);
    }
}
void init()
{
    gp = (Graph **)calloc(size, size * sizeof(Graph *));
    arr = (int **)calloc(size, size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        gp[i] = (Graph *)malloc(sizeof(Graph));
        gp[i]->color = WHITE;
        gp[i]->prev = -1;
        gp[i]->f = gp[i]->d = inf;

        arr[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }
}
int main()
{
    int edges;
    printf("Enter num of vertices and edges[directed graph]: ");
    scanf("%d%d", &size, &edges);
    printf("enter edges from 0 to %d: ", size - 1);
    init();
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        scanf(" %d %d", &x, &y);
        arr[x][y] = 1;
    }
    DFS();

    return 0;
}