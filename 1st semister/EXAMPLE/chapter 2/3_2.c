#include <stdio.h>
int main(void)

{
    int ans;
    printf("What is 10 +14? ");
    scanf("%d", &ans);

    if (ans == 10 + 14)
        printf("Right!");
    else
    {
        printf("Sorry, you're wrong. Answer is 24");
    }
    return 0;
}