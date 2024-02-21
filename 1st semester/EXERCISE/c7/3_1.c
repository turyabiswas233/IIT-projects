#include <stdio.h>
//I have fixed the code
void myfunc(int *num, int min, int max);
int main(int argc, char const *argv[])
{
    int i;
    printf("Enter a number between 1 and 10: ");
    myfunc(&i, 1,10);
    printf("Number is : %d\n", i);
    return 0;
}

void myfunc(int *num, int min, int max){
    do {
        scanf("%d", num);
    }
    while(*num < min || *num > max);
}


