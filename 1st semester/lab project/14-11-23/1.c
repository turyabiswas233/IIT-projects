#include <stdio.h>
int printArr(int row, int col, int (*b)[3]);

int main(int argc, char const *argv[])
{
    int a[3][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int b[3][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printArr(3, 3, a);
    printf("%p\n%p\n",a,b-4);
    return 0;
}

int printArr(int row, int col, int (*b)[3])
{
    for (int i = 0; i < row ; i++)
    {
        for(int j=0;j<col;j++)
            printf("%p = %d ", (*b + i), b[i][j]);
        printf("\n");

        
    }
}

