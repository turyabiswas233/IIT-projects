#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double pounds;
    pounds = atof(argv[1]) / 16.0;
    printf("%f pounds\n", pounds);
    
    return 0;
}