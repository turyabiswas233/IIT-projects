#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{

    char words[][3][20] = {
        {
            "a",
            "apple",
        },
        {
            "b",
            "ball",
        },
        {"c", "c program"}};
    char str[20];
    scanf("%s", str);

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(words[i][0], str))
            continue;
        else
        {
            printf("%s\n", words[i][1]);
            return 0;
        }
    }
    printf("Not found\n");

    return 0;
}