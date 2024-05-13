#include <stdio.h>
#include <stdlib.h>

int getMinJumps(int arr[], int n)
{
    int counter = 0, i;
    for (i = 0; i < n; i++)
    {
        if (counter < n)
        {
            counter += 1;
        }
        i += arr[i];
    }
    if (i >= n)
        return counter;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 4, 3, 2, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    int counter = getMinJumps(arr, len);
    printf("%d\n", counter);

    return 0;
}
