#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{

    char *Berland;
    char *Birland;
    Berland = (char *)malloc(sizeof(char) * 1000);
    Birland = (char *)malloc(sizeof(char) * 1000);
    scanf(" %s %s", Berland, Birland);

    strrev(Berland);

    if (strcmp(Berland, Birland) == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}

/*
vxpqullmcbegsdskddortcvxyqlbvxmmkhevovnezubvpvnrcajpxraeaxizgaowtfkzywvhnbgzsxbhkaipcmoumtikkiyyaivg
gviayyikkitmuomcpiakhbxszgbnhvwyzkftwoagzixaearxpjacrnvpvbuzenvovehkmmxvblqyxvctroddksdsgebcmlluqpxv

*/