#include <stdio.h>
int main(void)
{
    unsigned u;
    long l;
    short s;
    printf("Enter an unsigned: ");
    scanf("%u", &u);

    printf("Enter an long: ");
    scanf("%ld", &l);

    printf("Enter a short: ");
    scanf("%hd", &s);

    printf("%u %ld %hd\n", u, l, s);
    return 0;
}