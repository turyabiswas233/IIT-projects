#include <stdio.h>
int array[10] = {1, 2, 3, 4, 15, 50, 60, 70, 80, 90};
int binSearch(int firstIndex, int lastIndex, int x)
{
    int mid;
    if (firstIndex <= lastIndex)
    {
        mid = firstIndex + (lastIndex - firstIndex) / 2;
        printf("%d,%d: %d\n", firstIndex, lastIndex, mid);
        if (array[mid] == x)
            return mid;
        else if (array[mid] > x)
            return binSearch(firstIndex, mid - 1, x);
        else
            return binSearch(mid + 1, lastIndex, x);
    }
    else
        return -1;
}
int main()
{
    int len = 9;

    int x;

    printf("Enter a integer number: ");
    scanf("%d", &x);
    int index = binSearch(0, len, x);
    if (index == -1)
    {
        printf("Cannot find the value in array.\n");
    }
    else
    {
        printf("Index[%d]: %d\n", index, array[index]);
    }

    return 0;
}