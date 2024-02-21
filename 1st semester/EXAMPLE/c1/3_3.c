#include <stdio.h>
int main(int argc, char const *argv[])
{
    char i;

    for (i = getche(); i != 'q'; i = getche())
        ;
    printf("Found the q");

    return 0;
}
