#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct string
{
    char s[100];
} String;

struct cities
{
    int size;
    String *cities;
} Cities;

void initGraph(int A[][Cities.size])
{
    int size = Cities.size;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            A[i][j] = 0;
}
int main(int argc, char const *argv[])
{

    int numOfCity, routes;
    printf("Enter number of cities: ");
    scanf("%d ", &numOfCity);

    int A[numOfCity][numOfCity];
    Cities.size = numOfCity;
    Cities.cities = (String *)malloc(sizeof(String) * numOfCity);

    for (int i = 0; i < numOfCity; i++)
    {
        fgets(Cities.cities[i].s, 99, stdin);
        int len = strlen(Cities.cities[i].s);
        Cities.cities[i].s[len - 1] = '\0';
    }

    printf("Print Cities: [");
    for (int i = 0; i < numOfCity; i++)
    {
        printf("%s,", Cities.cities[i]);
        if (i == numOfCity - 1)
            printf("]\n");
    }

    printf("Enter number of routes: ");
    scanf(" %d", &routes);
    initGraph(A);
    for (int i = 0; i < routes; i++)
    {
        int s, d, price;
        do
        {
            scanf(" %d %d %d", &s, &d, &price);

            if (s >= numOfCity || d >= numOfCity || price <= 0)
            {
                printf("Wrong city index or price, try again!\n");
            }
        } while (s >= numOfCity || d >= numOfCity || price <= 0);

        A[s][d] = price;
    }

    printf("Print Routes: \n");
    for (int i = 0; i < numOfCity; i++)
    {
        for (int j = 0; j < numOfCity; j++)
        {
            if (A[i][j] != 0)
            {
                printf("%s -> %s : %d BDT\n", Cities.cities[i], Cities.cities[j], A[i][j]);
            }
        }
    }
    int in[numOfCity], out[numOfCity];

    for (int i = 0; i < numOfCity; i++)
    {
        in[i] = out[i] = 0;
        for (int j = 0; j < numOfCity; j++)
        {
            if (A[i][j] != 0)
            {
                out[i] += 1;
            }
            if (A[j][i] != 0)
            {
                in[i] += 1;
            }
        }
        printf("%s-> %2d %2d = %02d\n", Cities.cities[i], in[i], out[i], in[i] + out[i]);
    }

    return 0;
}
