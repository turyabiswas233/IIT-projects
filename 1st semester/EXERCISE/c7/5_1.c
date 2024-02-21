#include <stdio.h>
double ftom(double f);
int main(int argc, char const *argv[])
{
    double feet;
    printf("Enter feet: ");
    scanf("%lf", &feet);
    printf("Meter: %f", ftom(feet));
    return 0;
}
double ftom(double f){
    return f/3.28;
}
