#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    char ch;
    ch = 'a';

    for (i = 0; ch != 'q'; i++)
    {
        /* code */
        printf("Pass: %d\n", i);
        ch = getche();
    }

    return 0;
}
