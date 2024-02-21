#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char s[100], t[100];
    int i, j, flag = 0;
    scanf("%s", s);
    int lens = strlen(s);
    scanf("%s", t);

    for (i = 0, j = lens - 1; i < lens, j >= 0; j--, i++)
    {

        if (s[i] == t[j])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("YES");

    else
        printf("NO");

    return 0;
}
