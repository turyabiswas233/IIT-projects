#include <stdio.h>
int main(int argc, char const *argv[])
{
    int ans;
    for (int i = 0; i < 11; i++)
    {
        /* code */
        printf("What is %d +%d? ", i, i);
        scanf("%d", &ans);

        if (ans == i + i)
            printf("Right!\n");
        else
        {
            printf("Sorry, you're wrong. Answer is 24\n");
        }
    }
    return 0;
}
