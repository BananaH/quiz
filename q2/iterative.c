#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char smallest_character(char str[], char c){
	for(int i=0;i<strlen(str);i++){
		if(((int)c)<((int)str[i]))
			return str[i];
	}
	return str[0];
}

int main(int argc,char *argv[]){
	smallest_character(argv[1],argv[2][0]);
    	return 0;
}