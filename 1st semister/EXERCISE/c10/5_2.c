#include <stdio.h>
union i_to_l
{
    int i;
    long l;
};

int main(void)
{
    union i_to_l itol;
    itol.i = 123456;
    itol.l = itol.i;
    printf("i=%d\nl=%ld\n", itol.i, itol.l);
    return 0;
}
