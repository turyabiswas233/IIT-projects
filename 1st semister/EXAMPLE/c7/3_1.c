#include <stdio.h>
void prompt(char *msg, int *num);
int main(int argc, char const *argv[])
{
    int i;
    prompt("Enter a num: ", &i);
    printf("Your number is: %d\n", i);
    return 0;
}

void prompt(char *msg, int *num) {
    printf(msg);
    scanf("%d", num);
}
