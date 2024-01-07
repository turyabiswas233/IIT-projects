#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define CAT_FILE "catfile.bin"

int menu(void);
void display(int i);
void authSearch(void);
void titleSearch(void);
void enter(void);
void save(void);
void load(void);

struct bookType
{
    unsigned date;    // copyright date
    unsigned char ed; // edition
    unsigned pages;   // lenght of book
};

struct catalog
{
    char name[80];
    char title[80];
    char pub[80];
    struct bookType book;
} cat[MAX];

int top = 0; // last loaction used

// main function
int main()
{
    int choice;

    load();
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            enter(); // enter books
            break;
        case 2:
            authSearch(); // search by author
            break;
        case 3:
            titleSearch(); // search by title
            break;
        case 4:
            save();
        default:
            break;
        }
    } while (choice != 5);

    return 0;
}

// show menu
int menu(void)
{
    int i;
    char str[80];

    printf("Card catalog:\n");
    printf("%4d. Enter books\n", 1);
    printf("%4d. Search by Author\n", 2);
    printf("%4d. Search by Title\n", 3);
    printf("%4d. Save catalog\n", 4);
    printf("%4d. Quit\n", 5);

    do
    {
        printf("Choose your selection: ");
        gets(str);
        i = atoi(str);
        printf("\n");
    } while (i < 1 || i > 5);
    return i;
}

// enter books into database
void enter(void)
{
    int i = 0;
    char temp[80];

    for (i = 0; i < MAX; i++)
    {
        printf("Enter author name (Enter to quit): ");
        gets(cat[i].name);
        if (!*cat[i].name)
            break;
        printf("Enter title[char *]: ");
        gets(cat[i].title);
        printf("Enter publisher[char *]: ");
        gets(cat[i].pub);
        printf("Enter copyright date[1-31][number]: ");
        gets(temp);
        cat[i].book.date = (unsigned)atoi(temp);
        printf("Enter edition[number]: ");
        gets(temp);
        cat[i].book.ed = (unsigned char)atoi(temp);
        printf("Enter number of pages[number]: ");
        gets(temp);
        cat[i].book.pages = (unsigned)atoi(temp);
    }
    top = i;
}

// search by author
void authSearch(void)
{
    char name[80];
    int i, found;
    printf("Name [80]: ");
    gets(name);

    found = 0;
    for (i = 0; i < top; i++)
    {
        if (!strcmp(name, cat[i].name))
        {
            display(i);
            found = 1;
            printf("\n");
            break;
        }
    }
    if (!found)
        printf("Not found\n");
}

// search by title
void titleSearch(void)
{
    char title[80];
    int i, found;
    printf("Title [80]: ");
    gets(title);

    found = 0;
    for (i = 0; i < top; i++)
    {
        if (!strcmp(title, cat[i].title))
        {
            display(i);
            found = 1;
            printf("\n");
            break;
        }
    }
    if (!found)
        printf("Not found\n");
}

// display catalog entry
void display(int i)
{
    printf("%s\n", cat[i].title);
    printf("by %s\n", cat[i].name);
    printf("Published by %s\n", cat[i].name);
    printf("Copyright: %u, edition: %u\n", cat[i].book.date, cat[i].book.ed);
    printf("Page: %u\n", cat[i].book.pages);
}

// load the castalog file
void load(void)
{
    FILE *fp;
    fp = fopen(CAT_FILE, "rb");
    if (fp == NULL)
    {
        printf("Catalog file not found\n");
        return;
    }

    if (fread(&top, sizeof top, 1, fp) != 1)
    {
        printf("Error reading count.\n");
        exit(1);
    }
    if (fread(cat, sizeof cat, 1, fp) != 1)
    {
        printf("Error reading count.\n");
        exit(1);
    }

    fclose(fp);
}

// save the catalog file
void save(void)
{
    FILE *fp;
    fp = fopen(CAT_FILE, "wb");
    if (fp == NULL)
    {
        printf("Catalog file not found\n");
        return;
    }
    if (fwrite(&top, sizeof top, 1, fp) != 1)
    {
        printf("Error writing count\n");
        exit(1);
    }
    if (fwrite(cat, sizeof cat, 1, fp) != 1)
    {
        printf("Error writing count\n");
        exit(1);
    }
    else
        printf("!!Data saved!!\n");
    fclose(fp);
}