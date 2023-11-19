#include <stdio.h>
#define len 5
int max(int x, int y)
{
    return x > y ? x : y;
}
int absV(int x, int y)
{
    int sm = x - y;
    return sm < 0 ? -sm : sm;
}
int min(int x, int y)
{
    return x > y ? y : x;
}
int maximumStrongPairXor(int *nums, size_t numSize)
{
    int maxV = *(nums) ^ *(nums);
    for (size_t i = 0; i < numSize; i++)
    {
        for (size_t j = i; j < numSize; j++)

        {

            // set max
            if (absV(*(nums + j), *(nums + i)) < min(*(nums + j), *(nums + i)))
            {
                maxV = max(maxV, (*(nums + j) ^ *(nums + i)));
                printf("%d\t", maxV);
            }
            printf("%d ^ %d = %d\n", *(nums + i), *(nums + j), *(nums + j) ^ *(nums + i));
        }
    }
    return maxV;
}

int main(int argc, char const *argv[])
{
    /* code */
    int arr[len] = {500, 3000, 2500, 510, 520};
    printf("%d\n", maximumStrongPairXor(arr, len));
    return 0;
}
