#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct city
{
    char s[50];
} *City;
int n = 0;
int findIndex(char *c)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(c, City[i].s) == 0)
        {
            return i;
        }
    }
    return -1;
}
void addCity(char *c, int loc)
{
    strcpy(City[loc].s, c);
}

void initGraph(int g[][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = 0;
}
int main()
{

    scanf("%d", &n);
    City = malloc(sizeof(struct city) * n);
    int graph[n][n];
    initGraph(graph);
    int loc = 0;
    for (int i = 0; i < n; i++)
    {
        struct city temp1, temp2;
        int price, loc1, loc2;
        scanf(" %s %s %d", temp1.s, temp2.s, &price);
        if (findIndex(temp1.s) != -1)
            ;
        else
        {
            addCity(temp1.s, loc);
            loc++;
        }
        if (findIndex(temp2.s) != -1)
            ;
        else
        {
            addCity(temp2.s, loc);
            loc++;
        }

        loc1 = findIndex(temp1.s);
        loc2 = findIndex(temp2.s);
        graph[loc1][loc2] = price;
    }

    printf("\nCity: ");
    for (int i = 0; i < n; i++)
    {
        printf("%s ", City[i].s);
    }
    printf("\nGraph: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*
3
f a 3
a d 5
f d 2
*/