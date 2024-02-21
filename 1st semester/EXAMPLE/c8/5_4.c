#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i;

    printf("%d %f%n", 100, 123.23, &i);
    printf("\n%d character output so far", i);

    return 0;
}
