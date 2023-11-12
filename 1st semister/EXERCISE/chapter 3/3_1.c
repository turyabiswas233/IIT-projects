#include <stdio.h>
int main(int argc, char const *argv[])
{
    int dis, speed;
    printf("Enter distance(m) and speed(m/s): ");
    scanf("%d%d", &dis, &speed);
    printf("Time is : %0.2f s\n", (float)dis / speed);
    return 0;
}
