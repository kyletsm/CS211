#include <stdlib.h>
#include <stdio.h>

int get(unsigned short x, unsigned short n){
	unsigned short temp;
	temp =1;
	temp =temp<<n;
	unsigned short result = (x&temp)&&1;
	return result;
}

int main(int argc, char* argv[]){
	unsigned short x = atoi(argv[1]);
	unsigned short left,right;
	short palindrome =1;
	int i;
	int j = 15;
	for(i=0;i<=j;i++){
		left = get(x,j);
		right = get(x,i);
		if(left != right){
			palindrome =0;
		}
		j--;
	}
	
	if(palindrome ==1){
		printf("Is-Palindrome\n");
	}else{
		printf("Not-Palindrome\n");
	}
	
	
	return 0;
}
