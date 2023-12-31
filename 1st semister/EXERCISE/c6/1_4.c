#include <stdio.h>
int main(int argc, char const *argv[])
{
    int *p;
    int i;
    p = &i;
    for (i = 0; i < 10; i++)
    {
        /* code */
        printf("%p :: %d\n", p, *p);
        // *(p) = *p + i;
    }

    return 0;
}
