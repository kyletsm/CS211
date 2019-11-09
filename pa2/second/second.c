#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parity(unsigned short num){//even parity = 1 odd parity = 0
	unsigned short x = num;
	x = x^(x>>8);
	x = x^(x>>4);
	x = x^(x>>2);
	x = x^(x>>1);
	x = (~x)&1;
	return x;
}

int pairs(unsigned short num){
	unsigned short x = num;
	unsigned short y=3;
	unsigned short temp;
	int i,count;
	for(i=0;i<16;i++){
		temp = x&y;
		if(temp == 3){
			count++;
			x=x>>2;
		}else{
			x=x>>1;
		}
	}

	return count;
}

int main(int argc, char* argv[]){
	unsigned short x = atoi(argv[1]);
	
	
	unsigned short p;
	p = parity(x);
	if(p == 1){
		printf("Even-Parity\t");

	}else if(p == 0){
		printf("Odd-Parity\t");
	}
	unsigned short numPairs;
	numPairs = pairs(x);
	printf("%hu\n", numPairs);
	
	return 0;
}
