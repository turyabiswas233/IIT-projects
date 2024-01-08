#include<stdio.h>
int main(){
    while (!kbhit())
    {
       printf("%c",'.');
    }
}