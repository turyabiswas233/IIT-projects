#include <stdio.h>
#include <string.h>
void reverse(char *str);
int main(int argc, char const *argv[])
{
    char str[100];
    printf("Write a string [without <space>]:");
    scanf("%s", str);
    reverse(str);
    return 0;
}
void reverse(char *str)
{
    int len = strlen(str);
    char *temp = str + len - 1;
    for (int i = 0; i < len; i++)
    {
        printf("%c", *(temp - i));
    }
}