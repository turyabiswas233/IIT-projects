#include <stdio.h>
int main()
{
    int count = 0,c=1;
    for (int j = 0; j < 6; j++)
    {
        /* code */
        if (j % 2 == 1)
            for (int i = 0; i < 11; i++)
            {
                /* code */
                if (4 * count + 2 == i)
                {
                    printf(" %d ", count +j);
                    count++;c++;
                }
                else if ((i + 1) % 4 == 0)
                    printf("|");
            }
        
        else
        {
            if(j>1)for (int k = 0; k < 5; k++)
            {
                /* code */
                printf("%s",k%2==1 ? "+":"---");
            }
        }
        count = 0;
        printf("\n");
    }
}