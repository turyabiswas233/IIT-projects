#include <stdio.h>

float avg(float *f);

int main() {
    float f[10];
    for (int i = 0; i < 10; i++)
    {
        scanf(" %f", &f[i]);
    }
    float result = avg(f);
    printf("The average is : %f\n", result);
    
    
    return 0;
}

float avg(float *f) {
    
    int i =0;
    float avg = 0;
     for (i = 0; i < 10; i++)
    {
        printf("%d = %0.2f\n",i, f[i]);
        avg+=f[i];
    }
    return avg / (i);
}
