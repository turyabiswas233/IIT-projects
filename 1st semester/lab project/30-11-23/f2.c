#include <stdio.h>
#include <string.h>
int main()
{
    // FILE *fp;
    // fp = fopen("data.txt", "w");
    
    // if(fp == NULL) printf("File not found\n");
    char s[10000];
    FILE *fp = fopen("data.txt","r");
    fscanf(fp,"%s",s);
    fclose(fp);

    int len = strlen(s);
    int counter=0;
    for (int i = 0; i < len; i++)
    {
        if(s[i]==' ') counter++; 
    }

    printf("Words: %d\n",counter);
    
    

    return 0;
}
