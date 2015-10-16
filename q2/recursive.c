/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20
int level = 0;

char smallest_character(char str[], char c){
	char ans='?';
	level++;
	if((int)(*str)!=0){
		if((int)(*str)>(int)c){
			level--;
			return *str;
		}
		else
			ans = smallest_character((str+1),c);
		if(ans=='?'&&level==1){
			level--;
			return *str;
		}
		else{
			level--;
			return ans;
		}
	}
	else{
		level--;
		return ans;
	}
}

int main()
{
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
