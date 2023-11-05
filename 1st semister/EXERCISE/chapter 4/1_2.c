#include <stdio.h>
int main()
{
    unsigned int dis, res;
    printf("Enter a distance(in miles): ");
    scanf("%ld", &dis);

    res = dis / (186000);
    printf("It will take %ld Lights to travel %ld miles\n", res, dis);
    return 0;
}