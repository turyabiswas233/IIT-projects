#include <stdio.h>
void f1(void);
int max;
int main()
{
    max = 10;
    f1();
    return 0;
}
void f1(void)
{
    int i;
    for (i = 0; i < max; i++)
        printf("%d", i);
}