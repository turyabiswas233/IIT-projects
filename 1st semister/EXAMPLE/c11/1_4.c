#include <stdio.h>

void f(void)
{
    static int stop = 0;
    stop++;
    if (stop >= 999999)
        return;
    printf("%d ", stop % 20);
    f(); // recursive call
}
int main(int argc, char const *argv[])
{
    f();
    return 0;
}
