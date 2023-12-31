#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    char f[100],c;
    printf("enter the file name to erase: ");
    fgets(f,100,stdin);
    printf("are you sure?(Y \N)\n");
    scanf("%c",&c);
    if(c=='Y')
        if(remove(f))
            printf("file not found\n");
    //shun, ami eta onk perfectly sundor kre krsilam T.T sob dlt hoilo haire amk diti sob file tai bechebjaitonkjnbhhhhfnfnfififiowefiif689598
    // dara, mosha 😒😒😒 amk kmrai na :)
    return 0;

}