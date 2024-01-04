#include <stdio.h>
int main()
{
    int i, count[10];
    int isMatched = 0;
    for (i = 0; i < 10; i++)
    {
        scanf(" %d", &count[i]);
    }
    for (i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
            if (count[i] == count[j])
            {
                printf("%d is matched\n", count[i]);
                isMatched = isMatched ? isMatched : !isMatched;
            }
    }
    printf("\nisMatched: %d\n\n", isMatched);
    if (!isMatched)
        printf("No number matched!!\n");

    else
        printf("Some are found!!\n");
    return 0;
}
// 1 2 3 4 5 6 7 8 9 10