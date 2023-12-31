#include <stdio.h>
int main(void)
{
    int answer, count;
    int again;

    for (count = 1; count < 11; count++)
    {
        printf("What is %d ... %d? ", count, count);
        scanf("%d", &answer);
        if (answer == count + count)
            printf("Right!\n");
        else
        {

            printf("Sorry, you're wrong\n");
            printf("Try again.\n ");
            printf("\nWhat is %d + %d?", count, count);
            scanf("%d", &answer);

            if (answer == count + count)
                printf("Right!\n");
            else
                printf("Wrong, the answer is %d\n", count + count);
        }
    }
    return 0;
}