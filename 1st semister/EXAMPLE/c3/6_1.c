#include <stdio.h>
int main(int argc, char const *argv[])
{
    int ans, count, chances, right;
    for (count = 1; count <= 10; count++)
    {
        printf("What is %d + %d?", count, count);
        scanf("%d", &ans);

        if (count * 2 == ans)
            printf("Right!\n");
        else
        {
            printf("Sorry, you're wrong.\n");
            printf("Try again!\n");

            right = 0;
            for (chances = 0; chances < 3 && !right; chances++)
            {
                printf("What is %d + %d? ", count, count);
                scanf("%d", &ans);
                if (count * 2 == ans)
                {
                    printf("Right!\n");
                    right = 1;
                }
            }
            if (!right)
                printf("The answer is %d.\n", count * 2);
        }
    }

    return 0;
}
