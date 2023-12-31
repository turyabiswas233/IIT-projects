// the program is written in parameterized function
#include <stdio.h>
#define SOUND_SPEED 1129.00
float soundspeed(float dis)
{
    return dis / SOUND_SPEED;
}
int main(int argc, char const *argv[])
{
    float s_speed;
    printf("Enter distance in feet for one sound: ");
    scanf("%f", &s_speed);
    printf("%0.2f seconds will take to travel the sound \n", soundspeed(s_speed));

    return 0;
}
