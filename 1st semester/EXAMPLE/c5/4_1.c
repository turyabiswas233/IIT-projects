#include <stdio.h>
int main()
{
    int serverUser[5][2] = {
        1,
        14,
        2,
        28,
        3,
        19,
        4,
        8,
        5,
        15,
    };
    int server, i;

    printf("Enter the server number: ");
    scanf("%d", &server);
    for (i = 0; i < 5; i++)
    {
        if (server == serverUser[i][0])
        {
            printf("There are %d users on server %d.\n", serverUser[i][1], server);
            break;
        }
    }
    if (i == 5)
        printf("Server not listed.\n");
    return 0;
}