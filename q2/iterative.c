/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char smallest_character(char str[], char c){
	int num=0;
	while((int)str[num]!=127)
		num++;
	for(int i=0;i<num;i++){
		if(((int)c)<((int)str[i]))
			return str[i];
	}
	return str[0];
}

int main()
{
	char a[5] = {'c','f','j','p','v'};
	char b[3] = {'c','c','k'};
	int ai =strlen(a);
	int bi =strlen(b);
	printf("%s \n", a);
	printf("%s \n", b);
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
