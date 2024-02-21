#include <stdio.h>
#include <string.h>
char words[][2][40] = {
    "dog",
    "Hund",
    "no",
    "nein",
    "year",
    "Jahr",
    "child",
    "Kind",
    "I",
    "Ich",
    "drive",
    "fahren",
    "house",
    "Haus",
    "to",
    "zu",
    "",
    ""};
int main(void)
{
    char english[80];
    int i;
    printf("Enter english word: ");
    gets(english);

    // look up words
    i = 0;
    // search while null string not yet encountered
    while (strcmp(words[i][0], ""))
    {
        if (!strcmp(words[i][0], english))
        {
            printf("German translation: %s\n", words[i][1]);
            break;
        }
        i++;
    }
    if (!strcmp(words[i][0], ""))
    {
        printf("Not in dictionary\n");
    }

    return 0;
}
