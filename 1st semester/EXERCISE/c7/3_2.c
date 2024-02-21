#include <stdio.h>
void prompt(char *msg, char *str);
int main(){
	char *str;
	prompt("Enter a string: \0", str);
	printf("Your string is: %s\n", str);

	return 0;
}
void prompt(char *msg, char *str){
	printf(msg);
	scanf("%s",str);
}
