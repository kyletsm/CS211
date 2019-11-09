#include <stdlib.h>
#include <stdio.h>

void printMatrix(int** matrix, int row, int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%d", matrix[i][j]);
			if(j != col-1)
				printf("\t");
		}
		if(i != row-1){
		printf("\n");}
	}
};
void multiply(int** matrix1, int** matrix2, int**matrix3, int row1, int col2, int row2){
	int i,j,k;
	for(i=0;i<row1;i++){
		for(j=0;j<col2;j++){
			for(k=0;k<row2;k++){
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
};

void freeMatrix(int** matrix,int row,int col){
	int i;
	for(i=0;i<row;i++){
		
		free(matrix[i]);
		
	}
}

int main(int argc, char** argv){
	FILE *input = fopen(argv[1], "r");
	int row1,col1,row2,col2,row3,col3;
	
	fscanf(input, "%d %d\n", &row1, &col1);
	int** matrix1 = malloc(row1*sizeof(int*));
	//printf("break1\n");
	//printf("%d\n", row1);
	//printf("%d\n", col1);
	int i;
	int j;
	int temp;
	for(i=0;i<row1;i++){
		matrix1[i] = malloc(col1*sizeof(int));//each row malloced with col1*sizeof(int)
		for(j=0;j<col1;j++){
			fscanf(input,"%d ", &temp);
		 	//printf("%d\n", temp);
			matrix1[i][j] = temp;
			//printf("%d\n", temp);
		}
		fscanf(input,"\n");
	}
	//printf("break99\n");
	//printMatrix(matrix1, row1, col1);
	fscanf(input,"%d %d\n",&row2,&col2);
	int** matrix2 = malloc(row2*sizeof(int*));
	if(col1 == row2){
		for(i=0;i<row2;i++){
			matrix2[i] = malloc(col2*sizeof(int));
			for(j=0;j<col2;j++){
				fscanf(input,"%d ", &temp);
				matrix2[i][j] = temp;
			}
			fscanf(input,"\n");
		}
		
	
	}else{
		printf("bad-matrices");
		return 0;
	}
	row3 = row1;
	col3 = col2;
	int** matrix3 = malloc(row3*sizeof(int*));
	for(i=0;i<row3;i++){
		matrix3[i] = malloc(col3*sizeof(int));
	}
	multiply(matrix1,matrix2,matrix3,row1,col2,row2);
	printMatrix(matrix3,row3,col3);
	

	freeMatrix(matrix1, row1,col1);
//	free(matrix1);
	freeMatrix(matrix2,row2,col2);
//	free(matrix2);
	freeMatrix(matrix3,row3,col3);
//	free(matrix3);
	fclose(input);
	return 0;
};
