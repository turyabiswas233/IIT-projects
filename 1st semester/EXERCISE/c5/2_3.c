#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char bigstr[1000] = "";
    char smstr[100];
    int len = 0;
    do
    {
        gets(smstr);
        len = strlen(bigstr) + strlen(smstr);
        if (!strcmp(smstr, "quit"))
            break;
        if (len > 1000)
            break;
        strcat(smstr, "\n");
        strcat(bigstr, smstr);
        printf("%d\n", len);
    } while (1);
    printf(bigstr);

    return 0;
}
// Lorem, ipsum dolor sit amet consectetur adipisicing elit. Hic ea non