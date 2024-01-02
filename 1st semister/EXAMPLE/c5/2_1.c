#include <stdio.h>
#include <string.h>
int main(void)
{
    char strl[80], str2[80];
    int i;
    printf("Enter the first string: ");
    gets(strl);
    printf("Enter the second string: ");
    gets(str2);
    /* see how long the strings are */
    printf("%s is %d chars long\n", strl, strlen(strl));
    printf("%s is %d chars long\n", str2, strlen(str2));
    /* compare the strings */
    i = strcmp(strl, str2);
    if (!i)
        printf("The strings are equa1.\n");
    else if (i < 0)
        printf("%s is less than %s\n", strl, str2);
    else
        printf("%s is greater than %s\n", strl, str2);

    if (strlen(strl) + strlen(str2) < 80)
    {
        strcat(strl, str2);
        printf("%s\n", strl);
    }
    strcpy(str2, strl);
    printf("%s %s\n", strl, str2);
    printf("i = %d\n", i);
    register i2;
    printf("i = %d\n", i2);
}