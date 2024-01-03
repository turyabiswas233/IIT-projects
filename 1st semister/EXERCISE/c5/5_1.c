#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    char english[][80] = {
        "avengers", "business", "currency", "destination", "Executive", "Fassination", "Grapify", "High-hill", "Illuminatee", "Juvenile", ""};

    int i;
    do
    {
        printf("\nEnter a digit (1-10): ");
        scanf("%d", &i);
        if (0 < i && i <= 10)
            printf("%s", toupper(english[i - 1]));
        else
            printf("<Invalid Index>");

    } while (i > 0 && i <= 10);

    return 0;
}
