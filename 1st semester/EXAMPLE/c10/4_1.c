#include <stdio.h>
struct b_type
{

    unsigned f : 2;
    unsigned l : 2;
} bt;

int main(int argc, char const *argv[])
{

    bt.f = 1;
    bt.l = 4;
    printf("%u %u\n", bt.f, bt.l);
}