#include <stdio.h>
int main(int argc, char const *argv[])
{
    char *one, *two, *three;
    one = "One ";
    two = "Two ";
    three = "Three ";
    // printf("%p\n%p\n%p\n", one, two, three);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (i != j && j != k && k != i)
                {
                    printf("\n");

                    switch (i)
                    {
                    case 0:
                        printf(one);
                        break;
                    case 1:
                        printf(two);
                        break;
                    case 2:
                        printf(three);
                        break;

                    default:
                        break;
                    }
                    switch (j)
                    {
                    case 0:
                        printf(one);
                        break;
                    case 1:
                        printf(two);
                        break;
                    case 2:
                        printf(three);
                        break;

                    default:
                        break;
                    }
                    switch (k)
                    {
                    case 0:
                        printf(one);
                        break;
                    case 1:
                        printf(two);
                        break;
                    case 2:
                        printf(three);
                        break;

                    default:
                        break;
                    }
                }
            }
        }
    }

    return 0;
}