#include <stdio.h>
struct s_type f(void);
struct s_type
{
    int i;
    double d;

} var1;
int main(int argc, char const *argv[])
{
    var1 = f();
    printf("%d %f\n", var1.i, var1.d);
    return 0;
}

struct s_type f(void)
{
    struct s_type temp;
    temp.i = 100;
    temp.d = 123.23;
    return temp;
};
