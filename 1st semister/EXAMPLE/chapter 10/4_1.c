#include <stdio.h>
struct b_type
{
    /* data */
    unsigned first : 32; // 32bit-5
    int x : 32;          // 32bit-5
    unsigned last : 32;  // 32bit-5
} bt;

int main(int argc, char const *argv[])
{
    /* code */
    printf("%d", sizeof(bt));
    return 0;
}
