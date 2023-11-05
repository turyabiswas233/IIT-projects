#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n], num = 0;
    for (int i = 0,j=1; i < n; i++,j*=10)
    {
        /* code */
        scanf("%d", &arr[i]);
        num += arr[i] * j;
    }
    printf("Number is = %d\n", num); // 1264

}