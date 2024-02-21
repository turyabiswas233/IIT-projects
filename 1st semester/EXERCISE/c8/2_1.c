#include<stdio.h>

int main(void){
    char ch;
    do{
        ch = getchar ();
        if(ch==EOF)
        {
            printf("error on input\n");
            break;
        }
        if((putchar('.'))==EOF)
        {
            printf("error on output\n");
            break;
        }
    }while(ch != '\n');
    return 0;
}