#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char name[] = "Tom ";
    int l1, l2;
    l1 = strlen(name);
    printf(name);
    printf("%d\n", l1);
    strcpy(name, "Tom Brazwell lorema ipsum 123 ");
    printf(name);
    l2 = strlen(name);
    printf("%d\n", l2);
    return 0;
}
