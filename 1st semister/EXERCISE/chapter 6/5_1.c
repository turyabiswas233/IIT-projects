#include <stdio.h>
#include <string.h>
int main(void)
{

    char *p[][3] = {"Yes", "No", "Maybe. Rephrase the question"};

    char *q;
    scanf("%s", q);
    int len = strlen(q);
    for (int i = 0; q[i]; i++)
    {
        if (i == len % 3)
        {
            printf("%s\n", q[i]);
        }
    }

    printf(q);

    return 0;
}
