#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define max 3

//function
void infu();
void name();
void writer();
void publr();
void catalog();
void load();

//structure
struct book
{
    char cpydt[100];
    char edtn[100];
    int  prize;
    int  page;
};
struct catalog
{
    /* data */
    char name[100];
    char writer[100];
    char publr[100];
    struct book tp;
}*c;
int n;
//main function
int main(){
    //manu
    c=(struct catalog*)malloc(sizeof(struct catalog)*100);
    if(c==NULL)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    printf("\tcard catalog\n");
    printf("\t------------\n");
    printf("1 for enter information\n");
    printf("2 for search by book name\n");
    printf("3 for search by writer name\n");
    printf("4 for search by publication name\n");
    printf("5 for save the catalog in a file\n");
    printf("6 for load the file\n");
    printf("7 for quit\n");
    //choice
    int choice;
    while (1)
    {
        /* code */
        printf("enter your choice(press 1-7):");
        scanf("%d",&choice);
        printf("\n");
        if(choice==7)    break;
        switch (choice)
        {
            case 1:
                infu();
                break;
            case 2:
                name();
                break;    
            case 3:
                writer();
                break;
            case 4:
                publr();
                break;
            case 5:
                catalog();
                break;
            case 6:
                load();
                break;
            default:   
                printf("error");
                break;
        }
    }
    return 0;
}
//information 
void infu(){
    int i;
    printf("enter the number of books:");
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        printf("enter the book name: ");
        fgets(c[i].name,100,stdin);
        printf("enter the book's writer name: ");
        fgets(c[i].writer,100,stdin);
        printf("enter the publication name: ");
        fgets(c[i].publr,100,stdin);
        printf("enter the copywrite date: ");
        fgets(c[i].tp.cpydt,100,stdin);
        printf("enter the edition: ");
        fgets(c[i].tp.edtn,100,stdin);
        printf("entern the prize: ");
        scanf("%d",&c[i].tp.prize);
        printf("enter the number of pages: ");
        scanf("%d",&c[i].tp.page);
        getchar();
    }
}

void name(){
    char nm[100];
    printf("enter a book name: ");
    fgets(nm,100,stdin);
    int i,f=0;
    for(i=0;i<n;i++)
    {
        if(!(strcmp(n,c[i].name)))
        {
            f=1;
            break;
        }
    }
    if(f)
    {
      printf("found\n");
      printf("%s -> %s -> %s -> %s -> %s -> %d ->%d\n",c[i].name,c[i].writer,c[i].publr,c[i].tp.cpydt,c[i].tp.edtn,c[i].tp.page,c[i].tp.prize);
    }
    else    printf("not found\n");
    
}
//search bt writer name
void writer(){
    char w[100];
    printf("enter a writer name: ");
    fgets(w,100,stdin);
    int i, f=0;
    for( i=0;i<n;i++)
    {
        if(!(strcmp(w,c[i].writer)))
        {
            f=1;
            break;
        }
    }
    if(f)
    {
      printf("found\n");
      printf("%s -> %s -> %s -> %s -> %s -> %d ->%d\n",c[i].name,c[i].writer,c[i].publr,c[i].tp.cpydt,c[i].tp.edtn,c[i].tp.page,c[i].tp.prize);
    }
    else    printf("not found\n");
    
}
//search by publisher name
void publr(){
    char p[100];
    printf("enter publication name: ");
    fgets(p,100,stdin);
    int i,f=0;
    for( i=0;i<n;i++)
    {
        if(!(strcmp(p,c[i].publr)))
        {
            f=1;
            break;
        }
    }
    if(f)
    {
      printf("found\n");
      printf("%s -> %s -> %s -> %s -> %s -> %d -%d\n",c[i].name,c[i].writer,c[i].publr,c[i].tp.cpydt,c[i].tp.edtn,c[i].tp.page,c[i].tp.prize);
    }
    else    printf("not found\n");
}

//save to the file
void catalog(){
    FILE *fp;
    fp=fopen("book.txt","w");
    //fprintf(fp,"book name\twriter name\tpublication name\tcopywrite date\tedition\tprize\n");
    //fprintf(fp,"---------\t-----------\t----------------\t--------------\t-------\t-----\t");
    for(int i=0;i<n;i++)
        fprintf(fp,"%s--> %s--> %s--> %s--> %s--> %d--> %d\n",c[i].name,c[i].writer,c[i].publr,c[i].tp.cpydt,c[i].tp.edtn,c[i].tp.page,c[i].tp.prize);
    fclose(fp);
}

void load (void)
{
    FILE *fp;
    if((fp=fopen("book.txt","r"))==NULL)
    {
        printf("cannot open the file\n");
        exit(1);
    }
   for(int i=0;i<n;i++)
        fscanf(fp,"%s %s %s %s %s %d %d",c[i].name,c[i].writer,c[i].publr,c[i].tp.cpydt,c[i].tp.edtn,&c[i].tp.page,&c[i].tp.prize);
    fclose(fp);
}

//eta hoise?
// no pura hoinai ami bad dia raksi ar dekhi nai

// eta ki krslim?aita tui fget er oita thik krsili aro kj baki ase ami ar kori nai

//oh bujsi ami eta likhe rksi. nibo