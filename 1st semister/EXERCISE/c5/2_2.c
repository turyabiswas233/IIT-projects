/*#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[5];

    strcpy(str, "this is a test");
    printf(str);

    return 0;
}
*/
// YES, THERE IS WRONG WITH THIS CODE. IT SEEMS THE CODE IS TRYING TO COPY A STRING MORE LENGHT THEN THE BUFFER SIZE OF `STR`
// HERE IS THE CORRECT CODE:

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[5];

    strncpy(str, "this is a test", strlen("this is a test"));
    str[strlen("this is a test")] = '\0';
    printf(str);

    return 0;
}
