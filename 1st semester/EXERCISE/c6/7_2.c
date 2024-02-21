
#include <stdio.h>
void setMinOne(int *p);
int main()
{

    int *p;
    *p = 1569156;
    printf("value: %d (%p)\n", *p, p);
    setMinOne(p);
    printf("value: %d (%p)\n", *p, p);

    return 0;
}
void setMinOne(int *p)
{
    *p = -1;
}