#include <stdio.h>
#include <stdlib.h>
int main (int argc, char** argv){
	char* ptr = argv[1];	
	while(*ptr != '\0'){
		if(*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u'){
			printf("%c", *ptr);
		}
		ptr++;
	}
	return 0;
}
