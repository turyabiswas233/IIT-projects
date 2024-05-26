#include <stdio.h>
#include <stdlib.h>

int size = 0;
int **arr;
int *visited;

void DFS(int i)
{
    int j;
    printf("%d ");
    visited[i] = 1;
    for (j = 0; j < size; j++)
    {
        if (arr[i][j] == 1 && visited[j] == 0)
        {
            DFS(j);
        }
    }
}
void printgraph()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d", &size);
    arr = (int **)malloc(sizeof(int *) * size);
    if (arr == NULL)
    {
        exit(1);
    }
    visited = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
        if (arr[i] == NULL)
        {
            exit(1);
        }
        visited[i] = 0;
        /* code */
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }
    int edges;
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        arr[x][y] = arr[y][x] = 1;
    }
    printgraph();
    DFS(0);

    return 0;
}