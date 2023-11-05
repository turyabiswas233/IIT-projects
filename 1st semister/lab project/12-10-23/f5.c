#include <stdio.h>
int main()
{

    int arr[5] = {1, 6, 4, 5, 9};
    int max = arr[0], preNum;
    for (int i = 0; i < 5; i++)
    {
        /* code */
        if (max < arr[i])
        {
            preNum = max;
            max = arr[i];
        }
    }
    printf("2nd max is = %d\n", preNum);

    return 0;
}