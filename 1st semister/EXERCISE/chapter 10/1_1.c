
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define PH_BOOK "phonebook.txt"
#define max 1000
//structure
struct phnbk
{
   char name[20];
   char num[15];
}p[max];

int i;
// required functions
void showMenu();
void setList();
void findNum();
void saveList();
void loadList();
void trim(char *str);

int main()
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
    printf("Set List:\n");
    for (int j = 0; j < i; j++)
    {
        if ((strlen(p[j].name)) != 0 && strlen(p[j].num) != 0)
        {
            printf("\n##  If you have any unsaved data after you have opened the program, then those are gonna erased.  ##\n");
        }  
    }  
    i = 0;
    printf("## How many entry do you want? [ n>0 ]: ");
    scanf(" %d", &i);
    if (i < 1)
        return;
    for (int j = 0; j < i; j++)
    {
        /* code */
        printf("Person [%d]:\n", j + 1);
        printf("\tEnter name [20]: ");
        // fgets(phonebook[i][0], 10, stdout);
        scanf(" %s", p[j].name);
        printf("\tEnter PhoneNUM [15]: ");
        scanf(" %s", p[j].num);
    }
    printf("\nYOUR DATA HAS NOT YET SAVED. TO SAVE DATA, PLEASE CHOOSE (3) FROM THE MENU.\n");
    // show them in load section
}

// This will find details by searching number
void findNum()
{
    char nm[20];
    printf("Find name: \n");
    FILE *fp = fopen(PH_BOOK, "r");
    if (fp == NULL)
    {
        printf("\t##  NO RECORDS FOUND  ##\n");
        return;
    }
    // int db_num;
    // printf("##  How many data do you want? [n > 0]: ");
    // scanf(" %d", &db_num);
    // i = 0;
    // for (int j = 0; j < db_num; j++, i++)
    // {
    //     if (fread(p[j].name, 20, 1, fp) == 1 && fread(p[j].num, 15, 1, fp) == 1)
    //     {

    //         int len = strlen(p[j].name);
    //         p[j].name[len - 1] = '\0';
    //         len = strlen(p[j].num);
    //         p[j].num[len - 1] = '\0';
    //     }
    //     else
    //         break;
    // }
    printf("\tEnter name: ");
    scanf(" %s", &nm);
    for(int j=0;p[j].name != '\0';j++)
    {
        fread(p[j].name,20,1,fp);
        fread(p[j].num,15,1,fp);
        trim(p[j].name);
        if (!strcmp(nm, p[j].name))
        {
            printf("\n\t##  Target found in index [%d]:\n\tName: %s, Phone-num: %s\n", j + 1, p[j].name, p[j].num);
            
        }
    }
    
    printf("\t##    NUMBER NOT FOUND IN PHONEBOOK    ##\n");
    fclose(fp);
}

// This will save data into a file called <-- phonebook.txt -->
void saveList()
{
    printf("\nSaving list...");
    if (i == 0)
    {
        printf("Failed\n");
        return;
    }
    FILE *fp = fopen(PH_BOOK, "a");

    for (int j = 0; j < i; j++)
    {
        fprintf(fp, "%10s-%11s\n", p[j].name, p[j].num);
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
        printf("\t##  NO RECORDS FOUND  ##\n");
        return;
    }
    int db_num;
    printf("##  How many data do you want? [n > 0]: ");
    scanf(" %d", &db_num);
    i = 0;
    for (int j = 0; j < db_num; j++, i++)
    {
        if (fread(p[j].name, 20, 1, fp) == 1 && fread(p[j].num, 15, 1, fp) == 1)
        {

            int len = strlen(p[j].name);
            p[j].name[len - 1] = '\0';
            len = strlen(p[j].num);
            p[j].num[len - 1] = '\0';
        }
        else
            break;
    }
    fclose(fp);

    char sp = ' ';
    for (int j = 0; j < i; j++)
    {
        printf("\n\tPhonebook");
        printf("\n\t---------");
        printf("\nPerson-%d",j+ 1);
        printf("\n|______%10s", sp, p[j].name);
        printf("\n|____%11s", sp, p[j].num);
    }

    printf("\n\n##    Phone numbers has been loaded.    ##\n");
}

// A function to trim the leading and trailing spaces of a string
void trim(char *str)
{
    int k, j;
    // Find the index of the first non-space character
    for (k = 0; str[k] == ' '; k++) // k = 4
        ;
    // Shift the string to the left by i positions
    for (j = 0; str[k] != '\0'; k++, j++)
    {
        str[j] = str[k]; // str[0] = ' ' => str[0] = str[3] => ' ' -> 't'
    }
    // Add a null terminator at the end
    str[j] = '\0';
}
