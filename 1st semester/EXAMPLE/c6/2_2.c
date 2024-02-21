#include <stdio.h>
void part1();
void part2();
int main(void)
{
    part1();
    part2();
}
void part1()
{
    int *p, q;
    p = &q;
    q = 1;
    printf("OLD: %p = %d\n", p, *p);
    *p++;
    printf("NEW: %p = %d\n", p, *p);
}
void part2()
{
    int *p, q;
    p = &q;
    q = 1;
    printf("OLD: %p = %d\n", p, *p);
    (*p)++;
    printf("NEW: %p = %d\n", p, *p);
}