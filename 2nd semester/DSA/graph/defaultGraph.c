#include <stdio.h>

int main()
{
    int node;
    int x;

    printf("Number of node:");
    scanf("%d", &node);
    int graph[node][node];
    printf("Number of edge:");
    scanf("%d", &x);
    int edge[x][3];
    for (int i = 0; i < x; i++)
    {
        scanf(" %d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }
    int in[node];
    int out[node];

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < x; i++)
    {
        int r = edge[i][0];
        int col = edge[i][1];
        graph[r][col] = edge[i][2];
    }
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < node; i++)
    {
        out[i] = 0;
        in[i] = 0;
        for (int j = 0; j < node; j++)
        {
            out[i] = out[i] + graph[i][j];
            in[i] = in[i] + graph[j][i];
        }
    }
    printf(" IN   OUT\n");
    char c = 'A';
    for (int i = 0; i < node; i++)
    {
        printf("%c ", c + i);

        printf("%d  %3d\n", in[i], out[i]);
    }
    char e = 'A';
    char d = 'A';
    for (int i = 0; i < node; i++)
    {
        printf("%c=", e + i);
        char d = 'A';

        for (int j = 0; j < node; j++)
        {
            if (graph[i][j] == 1)
            {
                d = 'A';
                d = d + j;
                printf("%c ", d);
            }
        }
        if (d == 'A')
        {
            printf("NULL");
        }
        printf("\n");
    }
    char s = 'A';
    char p = 'A';
    char source, place;
    printf("What is the source: ");
    scanf("%c", &source);
    printf("Where do you want to go: ");
    scanf("%c", &place);
    int a = (int)(source - s);
    int b = (int)(place - p - 1);
    if (graph[a][b] > 0)
    {
        printf("Yes,possible\n");
        printf("The cost will be : %d\n", graph[a][b]);
    }
    else
        printf("No, impossible");
    return 0;
}
/*
0 1 10
0 4 15
1 2 5
2 3 15
4 3 20
4 5 5
5 1 25
5 2 100

*/