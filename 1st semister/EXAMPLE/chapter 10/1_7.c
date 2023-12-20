#include <stdio.h>
struct s_type
{
    int i;
    double d;
};
void f(struct s_type temp);
int main(int argc, char const *argv[])
{
    struct s_type var;
    var.i = 99;
    var.d = 98.6;
    f(var);
    return 0;
}
void f(struct s_type temp)
{
    printf("%d %f", temp.i, temp.d);
}