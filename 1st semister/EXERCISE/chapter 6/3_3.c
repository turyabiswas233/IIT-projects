#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], *ptr;
    printf("Enter a string: ");
    fgets(str, 100, stdin); // read string

    *ptr = str[0]; // find first space

    if (*ptr == ' ')
    { // if space is found
        printf("%s", str + 1);
    }
    else
        printf("%s", str);

    return 0;
}
