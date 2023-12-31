#include <stdio.h>
#include <string.h>
int main(void)
{
    char strl[] = "Pointers are fun to use ";
    char str2[80], *pl, *p2;
    /* make p point to end of strl */
    pl = strl + strlen(strl) - 1;
    p2 = str2;
    while (pl >= strl)
        *p2++ = *pl--;
    //  *null terminate str2 * /
    *p2 = '\0';
    printf("%s %s", strl, str2);
    return 0;
}