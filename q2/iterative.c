#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

char smallest_character(char str[], char c){
	int num=0;
	for(int i=0;i<strlen(str);i++){
		if(((int)c)<((int)str[i]))
			return str[i];
	}
	return str[0];
}

int main(){
	char a[size] = {'c','f','j','p','v'};
	char b[size] = {'c','c','k'};
	char ans=smallest_character(a,'a');
	printf("%c\n", ans);
	ans=smallest_character(a,'c');
	printf("%c\n", ans);
	ans=smallest_character(a,'z');
	printf("%c\n", ans);
	ans=smallest_character(b,'f');
	printf("%c\n", ans);
	return 0;
}