#include <stdio.h>
int max(int x, int y)
{
    return x > y ? x : y;
}
int main()
{
    int x, y, z;
    printf("Enter 3 numbers repeatedly: ");
    scanf("%d%d%d", &x, &y, &z);

    printf("MAX: %d\n", max(max(x, y), z));
    return 0;
}
