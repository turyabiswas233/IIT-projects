#include <stdio.h>
void rcopy(char *s1, char *s2) {
    if(*s2) {
        *s1++ = *s2++;
        rcopy(s1,s2);
    }
    else {
        *s1 = '\0';
    }
}
int main(int argc, char const *argv[])
{
    char str[50] = "This is python code\0";
    char str1[50];
    rcopy(str1,str);
    printf("%s", str);
    return 0;
}
