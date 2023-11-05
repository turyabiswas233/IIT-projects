#include <stdio.h>
// XOR code

int xor (int a, int b) {
    return (a && !b) || (!a && b);
} int main(int argc, char const *argv[])
{
    /* code */
    int p, q;
    printf("Enter 0 or 1 => (p) : ");
    scanf("%d", &p);
    printf("Enter 0 or 1 => (q) : ");
    scanf("%d", &q);

    printf("P XOR Q = %d", xor(p, q));

    return 0;
}
