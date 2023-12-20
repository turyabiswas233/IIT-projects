// the program is written in non-general function
#include <stdio.h>
#define SOUND_SPEED 1129.00
void soundspeed()
{
    float s_speed;
    printf("Enter distance in feet for one sound: ");
    scanf("%f", &s_speed);

    printf("%0.2f seconds will take to travel the sound \n", (s_speed / SOUND_SPEED));
}
int main(int argc, char const *argv[])
{
    soundspeed();
    return 0;
}
