#include <stdio.h>
void p_s(char *s) {
    if(*s) {
        p_s(s++);
    }
    else printf("%c",*s);
}
int main(int argc, char const *argv[])
{
    char *s = "Lorem ipsum 1507iogjiowj wejfiojwerfjw fjgioerhjgowhjfgiojioiojfg oawerjf iowfoijwefiojegjwsiofgjojgowie90wuigsjoiqjfiojskfj we9jdgjksj;klsjf l;ueroptuijafjasj\0";
    printf(s);
    return 0;
}
