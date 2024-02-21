#include <stdio.h>
#include <stdlib.h>
#define N 20 

int main()
{
    int n;
    scanf("%d", &n);
    if (n > N)
    { 
        exit(1);
    }
    else
    {
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            /* code */
            scanf("%d", &arr[i]);
            printf("%d \n",arr[i]);
        }
        
    }
}
/**
 * 
10
1 2 3 5 9 8 7 4 6 6

*/