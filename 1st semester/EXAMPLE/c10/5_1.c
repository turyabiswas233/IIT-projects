#include <stdio.h>
int encode(int i);

int main(void)
{
    int i, j;
    printf("Enter a number from 0 to 10000: ");
    scanf("%d", &i);
    j = encode(i); // encode it
    printf("%d encoded is %d\n", i, j);
    i = encode(j);
    printf("i decoded is %d\n", i);

    return 0;
}

int encode(int i)
{
    union crypt_type
    {
        int num;
        unsigned char c[2];
    } crypt;

    unsigned char ch;

    crypt.num = i;

    // swap bytes
    ch = crypt.c[0];
    crypt.c[0] = crypt.c[1];
    crypt.c[1] = ch;

    // return encoded integer
    return crypt.num;
}
