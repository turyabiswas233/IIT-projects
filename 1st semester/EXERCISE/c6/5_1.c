#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(char *argv[])
{

    char *p[3] = {"yes", "no", "Maybe. Rephrase the question"};

    char *query = (char *)malloc(sizeof(char) * 50);
    int len;

    do
    {
        fgets(query, 100, stdin);
        query[strcspn(query, "\n")] = '\0';
        if (!strcmp(query, "exit"))
        {
            printf("Exiting...\n");
            break;
        }
        len = strlen(query);
        printf("%s\n", p[len % 3]);
    } while (1);

    return 0;
}
