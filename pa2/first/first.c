#include <stdlib.h>
#include <stdio.h>


int main(int argc, char* argv[]){
	FILE *input = fopen(argv[1], "r");
	unsigned short x;
	fscanf(input,"%hu\n",&x);
	unsigned short temp;
	unsigned short n,v;
	char command[100];
	while(!feof(input)){
		//char command[4];
		fscanf(input, "%s %hu %hu\n",command, &n,&v);
		if(command[0] == 'g'){
			temp =1;
			temp =temp<<n;
			printf("%d\n", (x&temp)&&1);
		}else if(command[0] =='c'){
			temp = 1;
			temp = temp<<n;
			printf("%d\n", x^temp);
			x = x^temp;
		}else if(command[0] =='s'){
			temp = 1;
			temp = temp<<n;
			if(v == 1){
				printf("%d\n", x|temp);
				x = x|temp;
			}else if(v ==0){
				temp = ~temp;
				printf("%d\n",x&temp);
				x = x&temp;
			}
		}

	}
	
	fclose(input);


	return 0;
}


