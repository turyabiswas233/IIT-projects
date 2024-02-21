#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        /* code */
        int n, r, b, dif ;
        scanf("%d%d%d", &n, &r, &b);
        for (int i = 0; i < n;  )
        {
            /* code */
            dif = (r + b) / (b + 1);

            for (int j = 0; j < dif; j++)
            {
                /* code */
                printf("R"); 
                i++;
            }
            
            if (i < n)
            {
                printf("B");
                i++;
            }
            r-=dif;
            b--;
        }
        printf("\n");
    }
}