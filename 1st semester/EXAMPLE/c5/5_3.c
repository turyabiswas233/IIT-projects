#include <stdio.h>
int main(int argc, char const *argv[])
{
    char text[][80] = {
        "Ananda", "Merajul", "Noshin", "Morsha", "Mahfuj", "Kazi", "Turya", "Israfil", "Rony", "Dhanapati", "M.Rifat", "Dukkho", "Sadia", "Tanvir", "Assad", "A.Rifat", "Rahat", "Rudra", "Akidul", "Adnan", "Mush", "Suham", "Emam", "Mrinmoy", "Fahim", "Shahrin", "Nafish", "Fardin", "R.Rifat", "Sabbir", "Sizan", "Arman", ""};

    int i, j;

    // now display the name
    for (i = 0; text[i][0]; i++)
    {
        for (j = 0; text[i][j]; j++)
        {
            printf("%c", text[i][j], j);
        }
        printf("\t%s%02d\n", "--> 15", i + 1);
    }

    return 0;
}
