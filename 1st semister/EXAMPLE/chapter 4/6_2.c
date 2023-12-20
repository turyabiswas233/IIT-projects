#include <stdio.h>
int main(int argc, char const *argv[])
{
    short int si;
    long int li;

    li = 100000;
    si = li;

    printf("%hd", si);
    return 0;
}
