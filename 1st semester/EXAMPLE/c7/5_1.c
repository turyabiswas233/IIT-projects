#include <stdio.h>
int area(int l, int w);

int main(int argc, char const *argv[])
{
    printf("Area is %d\n",  area(10,13));
    return 0;
}
int area(int l, int w){
    return l*w;
}