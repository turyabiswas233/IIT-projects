#include <stdio.h>
void f1(int n[5]), f2(int n[]), f3(int *n);
int main(int argc, char const *argv[])
{

    int count[5] = {1, 2, 3, 4, 5};
    f1(count);
    f2(count);
    f3(count);
    return 0;
}

void f1(int n[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", n[i]);
    }
    printf("\n");
}
void f2(int n[])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", n[i]);
    }
    printf("\n");
}
void f3(int *n)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", n[i]);
    }
    printf("\n");
}