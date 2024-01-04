#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define PH_BOOK "phonebook.txt"

// required functions
void showMenu();
void setList();
void findNum();
void saveList();
void loadList();
void trim(char *str);

// required global variables
unsigned char phonebook[999][2][15];
int absInp = 1;

int main(int argc, char const *argv[])
{
    system("cls");
    unsigned char setMenu = '0';
    do
    {
        showMenu();
        printf("\nChoose your option: ");
        scanf(" %c", &setMenu);
        if (setMenu == '\n')
            continue;

        switch (setMenu)
        {
        case '1':
            setList();
            break;
        case '2':
            findNum();
            break;
        case '3':
            saveList();
            break;
        case '4':
            loadList();
            break;

        default:
            if (setMenu == '5')
            {
                printf("Exiting...\n");
                break;
            }
            else
            {
                printf("Invalid option [should be in 1 to 5]\n");
                break;
            }
        }

    } while (setMenu != '5');

    return 0;
}

// This will show 5 menu options in the shell
void showMenu()
{
    printf("\n1. Enter the names and numbers\n2. Find numbers\n3. Save directory to disk\n4. Load directory from disk\n5. Quit\n");
}
// This will set 3 names and number at 3 different row
void setList()
{
    if (strlen(phonebook[0][0]) != 0)
    {
        printf("\n##  If you have any unsaved data after you have opened the program, then those are gonna erased.  ##\n");
    }
    printf("Set List:\n");
    printf("## How many entry do you want? [ n>0 ]");
    scanf(" %d", &absInp);
    if (absInp < 1)
        return;
    for (int i = 0; i < absInp; i++)
    {
        /* code */
        printf("Person [%d]:\n", i + 1);
        printf("\tEnter name [10]: ");
        // fgets(phonebook[i][0], 10, stdout);
        scanf(" %s", phonebook[i][0]);
        printf("\tEnter PhoneNUM [11]: ");
        scanf(" %s", phonebook[i][1]);
    }
    printf("\nYour data has not yet saved. To save Data, please choose (4) from the menu option.\n");
    // show them in load section
}

// This will find details by searching number
void findNum()
{
    char phn[12];
    printf("Find Numbers: \n");
    // load data
    loadList();

    printf("\tEnter phone number: ");
    scanf(" %s", &phn);
    for (int i = 0; i < absInp; i++)
    {
        trim(phonebook[i][1]);
        if (!strcmp(phn, phonebook[i][1]))
        {
            printf("\n\t##  Target found in index [%d]:\n\tName: %s, Phone: %s\n", i + 1, phonebook[i][0], phonebook[i][1]);
            return;
        }
    }
    printf("\t##    NUMBER NOT FOUND IN PHONEBOOK    ##\n");
}

// This will save data into a file called <-- phonebook.txt -->
void saveList()
{
    printf("\nSaving list...");
    FILE *fp = fopen(PH_BOOK, "a");

    for (int i = 0; i < absInp; i++)
    {
        fprintf(fp, "%10s-%11s\n", phonebook[i][0], phonebook[i][1]);
    }

    fclose(fp);
    printf("Saved\n");
}

// This will load data from a file called <-- phonebook.txt -->
void loadList()
{
    printf("Loading List:-\n");
    FILE *fp = fopen(PH_BOOK, "r");
    if (fp == NULL)
    {
        printf("\t##    No records found    ##\n");
        return;
    }
    int db_num;
    printf("##  How many data do you want? [n > 0]: ");
    scanf(" %d", &db_num);
    absInp = 0;
    for (int i = 0; i < db_num; i++, absInp++)
    {
        if (fread(phonebook[i][0], 11, 1, fp) == 1 && fread(phonebook[i][1], 12, 1, fp) == 1)
        {

            int len = strlen(phonebook[i][0]);
            phonebook[i][0][len - 1] = '\0';
            len = strlen(phonebook[i][1]);
            phonebook[i][1][len - 1] = '\0';
        }
        else
            break;
    }
    fclose(fp);

    char sp = ' ';
    for (int i = 0; i < absInp; i++)
    {
        sp = (i < absInp - 1) ? '|' : ' ';
        if (i == 0)
            printf("\n\tPhonebook");
        printf("\n\t|____Person-%3d", i + 1);
        printf("\n\t%c    |____%10s", sp, phonebook[i][0]);
        printf("\n\t%c    |____%11s", sp, phonebook[i][1]);
    }

    printf("\n\n\t##    Phone numbers has been loaded.    ##\n");
}

// A function to trim the leading and trailing spaces of a string
void trim(char *str)
{
    int i, j;
    // Find the index of the first non-space character
    for (i = 0; str[i] == ' '; i++) // i = 4
        ;
    // Shift the string to the left by i positions
    for (j = 0; str[i] != '\0'; i++, j++)
    {
        str[j] = str[i]; // str[0] = ' ' => str[0] = str[3] => ' ' -> 't'
    }
    // Add a null terminator at the end
    str[j] = '\0';
}