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

int findCityId(String s)
{
    for (int i = 0; i < Cities.size; i++)
    {
        if (strcmp(s.s, Cities.cities[i].s) == 0)
        {
            return i;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{

    int numOfCity, routes;
    // printf("Enter number of cities: ");
    scanf("%d ", &numOfCity);

    int PriceList[numOfCity][numOfCity];
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
        printf("%s(%d) ", Cities.cities[i].s, i);
        if (i == numOfCity - 1)
            printf("]\n");
    }

    // printf("Enter number of routes: ");
    scanf(" %d", &routes);
    initGraph(PriceList);
    String s, d;
    int price, locS, locD;
    for (int i = 0; i < routes; i++)
    {

        do
        {
            scanf(" %s %s %d", s.s, d.s, &price);
            locS = findCityId(s);
            locD = findCityId(d);

            if (price <= 0 || locS == -1 || locD == -1)
            {
                printf("Wrong city index or price, try again!\n");
            }
        } while (price <= 0 || locS == -1 || locD == -1);

        PriceList[locS][locD] = price;
    }

    printf("Print Routes: \n");
    for (int i = 0; i < numOfCity; i++)
    {
        for (int j = 0; j < numOfCity; j++)
        {
            if (PriceList[i][j] != 0)
            {
                printf("%s -> %s : %d BDT\n", Cities.cities[i].s, Cities.cities[j].s, PriceList[i][j]);
            }
        }
    }
    int in[numOfCity], out[numOfCity];

    printf("\n\tIN   OUT\n");
    for (int i = 0; i < numOfCity; i++)
    {
        in[i] = out[i] = 0;
        for (int j = 0; j < numOfCity; j++)
        {
            if (PriceList[i][j] != 0)
            {
                out[i] += 1;
            }
            if (PriceList[j][i] != 0)
            {
                in[i] += 1;
            }
        }
        printf("%s-> %3d %5d\n", Cities.cities[i].s, in[i], out[i]);
    }
    printf("Enter source and destinatin");
    scanf(" %s %s", s.s,d.s);

    locS= findCityId(s);
    locD= findCityId(d);

    if(locD !=-1 && locS != -1 && PriceList[locS][locD] != 0) {
        printf("\nYes! From %s to %s it will cost only %d BDT\n", s.s,d.s,PriceList[locS][locD]);
    }
    else {
        printf("\nNo, you cannot travel from %s to %s.\n",s.s,d.s);

    }


    
    return 0;
}

/*

    dha, raj, syl, khu, ctg (5, 7)
    dhaka -> syl, khu
    raj -> dha, khu
    syl -> raj, ctg
    ctg -> syl

5
dha
raj
syl
khu
ctg
7
dha syl 250
dha khu 200
raj dha 320
raj khu 320
syl raj 400
ctg syl 350
syl ctg 350

*/