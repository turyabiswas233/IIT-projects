#include <stdio.h>
int main(int argc, char const *argv[])
{
    char arr[11], min;
    scanf("%s", arr);
    min = arr[0];
    for (int i = 1; i < 10; i++)
    {

        if (min < arr[i])
        {
            min = arr[i];
        }
    }

    printf("%c", min);
    return EOF;
}
