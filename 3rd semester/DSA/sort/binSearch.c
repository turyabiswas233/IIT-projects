#include <stdio.h>
#include <string.h>

struct String
{
    char *c;
};

int binarySearch(struct String arr[], struct String x, int size)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (strcmp(x.c, arr[mid].c) == 0)
            return mid + 1;
        else if (strcmp(arr[mid].c, x.c) < 0)
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return -1;
}
int main()
{
    struct String arr[] = {"afrid", "barkat", "shuvra Biswas", "turya biswas", "zamboo"};
    struct String x = {"shuvra Biswas"};
    printf("%d", binarySearch(arr, x, 5));
    return 0;
}