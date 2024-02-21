#include <stdio.h>
void result(int opt, float x, float y);
int main()
{
        int opt;
        float x, y;
        printf("Enter (1) for Add() or (2) for Sub(): ");
        scanf("%d", &opt);
        printf("Now enter any 2 numbers: ");
        scanf("%f%f", &x, &y);
        result(opt, x, y);
}

void result(int opt, float x, float y)
{
        if (opt == 1)
        {
                printf("Add: %f", x + y);
        }
        else if (opt == 2)
        {
                printf("Sub: %f", x - y);
        }
}