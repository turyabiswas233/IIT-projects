#include <stdio.h>
struct s_type
{
    int i;
    char ch;
    double d;
    char str[80];
} s;

int main()
{
    scanf("%d:", &s.i);
    scanf(" %c", &s.ch);
    scanf("%lf:", &s.d);
    scanf("%s:", s.str);
    printf("%d %c %f %s", s.i, s.ch, s.d, s.str);

    return 0;
}
