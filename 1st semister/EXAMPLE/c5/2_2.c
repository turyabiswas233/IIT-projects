#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char command[80], temp[80];
    int i, j;
    for (;;)
    {
        printf("Operation? ");
        gets(command);

        // see if user wants to stop
        if (!strcmp(command, "quite"))
            break;

        printf("Enter first number: ");
        gets(temp);
        i = atoi(temp);
        printf("Enter second number: ");
        gets(temp);
        j = atoi(temp);

        if (!strcmp(command, "add"))
            printf("%d", i + j);
        else if (!strcmp(command, "sub"))
            printf("%d", i - j);
        else if (!strcmp(command, "mul"))
            printf("%d", i * j);
        else if (!strcmp(command, "div"))
            printf("%d", i / j);
        else
            printf("Unknown command");
        printf("\n");
    }
    return 0;
}
