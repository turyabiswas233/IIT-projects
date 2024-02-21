#include <stdio.h>

float avg();

int main() {
    float result = avg();
    printf("The average is: %.2f\n", result);
    return 0;
}

float avg() {
    float sum = 0, num;
    int i; 
    for (i = 0; i < 10; i++) {
        scanf("%f", &num);
        sum += num;
    }
    return sum / 10.0;
}
