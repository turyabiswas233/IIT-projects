#include <stdio.h>
#define MAGIC 1723
int game();
int main()
{
    for (int i = 0; i < 100; i++)
    {
        /* code */
        int terminate = game();
        if (terminate)
        {
            break;
        }
    }

    return 0;
}

int game()
{
    int num;
    printf("\t\t\tEnter your MAGIC number: ");
    scanf("%d", &num);
    if (num == MAGIC)
    {
        printf("\t\t\t########____ CONGRATULATIONS ____########\t It is RIGHT!\n");
        return 1;
    }
    else
    {

        printf("\t\t\t########____  WRONG ____########\tIt is %s\n", num > MAGIC ? "HIGH" : "LOW");
        return 0;
    }
}
