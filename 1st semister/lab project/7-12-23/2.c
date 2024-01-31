#include <stdio.h>
typedef struct Rec
{
    unsigned int a;
    unsigned short int b;
    unsigned char c;
};
int main()
{

    /* code */
    struct Rec r;
    printf("Size a: %d\n", sizeof(r.a));
    printf("Size b: %d\n", sizeof(r.b));
    printf("Size c: %d\n", sizeof(r.c));
    printf("Size r: %d\n", sizeof(r));
    return 0;
}
