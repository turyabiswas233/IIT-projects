#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[6] = {1, 2, 3, 4, 5, 5}, check[5] = {0};
    int x;
    scanf("%d", &x);

    for (int i = 0, j = 0; i < 6; i++)
    {
        if (x == arr[i])
        {
            check[j] = i;
            j++;
        }
        // if (j - 1 == 0)
        //     printf("%d is found in : ", x);
        if (check[j - 1] != 0)
            printf("%dth ", check[j - 1]+1); // print index number
    }
    if (check[0] == 0)
        printf("No data found!!\n");

    return 0;
}
