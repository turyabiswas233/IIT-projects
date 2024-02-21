#include <stdio.h>
#define max(x,y) x>y ? x : y
int main(){
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    if(x & 1) {
        printf("It is ODD\n");
    }
    else printf("It is EVEN\n");

    printf("%d", max(2,3));
    
}