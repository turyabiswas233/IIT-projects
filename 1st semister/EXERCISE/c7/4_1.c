#include <stdio.h>
int lexicograph(char *s1, char *s2)
{

    if (*s1 == *s2)
    {
        lexicograph(s1+1, s2+1);
    }
    else if (*s1 > *s2)
    {
        return 1;
    }
    else
        return -1;
}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        puts("Argument error\n");
        return 0;
    }
    int lexChk = lexicograph(argv[1], argv[2]);
    switch (lexChk)
    {
    case 1:
        printf("%s < %s\n", argv[2], argv[1]);
        break;
    case -1:
        printf("%s < %s\n", argv[1], argv[2]);
        break;

    default:
        break;
    }

    return 0;
}
