#include <stdio.h>
struct bits
{
    unsigned char a[8];
};
union data
{
    struct bits bit;
    unsigned int x;
};
void encoder(char *x)
{
    for (int i = 0, j = 7; i < 8 / 2, j > 8 / 2; j--, i++)
    {
        unsigned char tmp = *(x + i);
        *(x + i) = *(x + j);
        *(x + j) = tmp;
    }
}
int main(int argc, char const *argv[])
{
    union data db;
    db.x = 50;

    printf("Root value: %d\n", db.x);
    encoder(db.bit.a);
    printf("Encoded value: %d\n", db.x);
    encoder(db.bit.a);
    printf("Decoded value: %d\n", db.x);

    return 0;
}
