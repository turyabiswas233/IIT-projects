#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double pounds;
    if(argc != 2) {
        printf("Usage CONVERT <ounces>\n");
        printf("Try again\n");
        exit(EXIT_FAILURE);
    }
    pounds = atof(argv[1])/16.0;
    printf("%f pounds\n", pounds);
    return 0;
}
