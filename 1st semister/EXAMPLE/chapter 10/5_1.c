#include <stdio.h>
int encode(int i);

int main(void)
{
    int i;
    i = encode(10); // encode it
    printf("10 encoded is %d\n", i);
    i = encode(i);
    printf("i decoded is %d\n", i);

    return 0;
}

int encode(int i)
{
    union crypt_type
    {
        /* data */
    };
}
