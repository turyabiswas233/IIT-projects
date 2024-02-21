#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char sen[1000];
    int j;
    gets(sen);
    int len = strlen(sen);

    for (int i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
            if ((('0' <= sen[j] && sen[j] <= '9') || (sen[j] >= 'A' && sen[j] <= 'Z') || (sen[j] >= 'a' && sen[j] <= 'z')))
                continue;
            else
            {
                char temp = sen[j + 1];
                sen[j + 1] = sen[j];
                sen[j] = temp;
            } 
    }
    puts(sen);

    return 0;
}
