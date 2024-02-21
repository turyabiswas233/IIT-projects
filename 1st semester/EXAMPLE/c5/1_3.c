#include <stdio.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    char mess[80];
    int i;
    printf("Enter message (less than 80 character): ");
    for ( i = 0; i < 80; i++)
    {
        mess[i] = getche();
        if(mess[i] =='\r') break;
    }
    printf("\n");

    for (i=0;mess[i]!= '\r';i++) {
        printf("%c", mess[i]+1);
    }
    
    return 0;
}
