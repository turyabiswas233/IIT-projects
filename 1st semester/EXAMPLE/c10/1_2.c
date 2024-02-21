#include <stdio.h>
struct s_type
{
    /* data */
    int i;        // 4
    char ch;      // 1
    double d;     // 8
    char str[80]; // 80
};

int main(int argc, char const *argv[])
{
    printf("s_type is %d bytes long", sizeof(struct s_type));
    return 0;
}
