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

int main(int argc,char *argv[]){
	smallest_character(argv[1],argv[2][0]);
    	return 0;
}
