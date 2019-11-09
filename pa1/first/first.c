#include <stdlib.h>
#include <stdio.h>

void selectionSort(int arr[],int n);

int main(int argc, char* argv[]){
  FILE *input = fopen(argv[1], "r");
  int arr[20];
  int numElements;

  fscanf(input, "%d\n", &numElements);
  //printf("%d\n", numElements);
  //fscanf(input, "%d%d%d\n", &arr[0], &arr[1],&arr[2]);
  //printf("%d %d %d\n", arr[0], arr[1], arr[2]);
  int i;
  for(i =0;i<numElements;i++){
	fscanf(input, "%d", &arr[i]);
	//printf("%d \n", arr[i]);
  }
  int odd[20];
  int even[20];
  int j=0;
  int k=0;
  for(i=0;i<numElements;i++){
	if((arr[i] % 2)==0){
		even[j]=arr[i];
		j++;
	}else{
		odd[k]=arr[i];
		k++;
	}
  }
  selectionSort(even,j);
  selectionSort(odd,k);
  //for(i=0;i<j;i++)
//	printf("%d \n",even[i]);
  //for(i=0;i<k;i++)
    //    printf("%d \n",odd[i]);
  
  for(i=0;i<j;i++){
  	arr[i] = even[i];
  }
  int n = numElements;
  for(i=0;i<k;i++){
	n--;
	arr[n]=odd[i];
  }
  for(i=0;i<numElements;i++){
  	printf("%d\t", arr[i]);
  }
	//printf("\n");
  fclose(input);
  return 0;
};

void selectionSort(int arr[], int n){
	int i;
	int j;
	int min;

	for (i=0; i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if (arr[j] < arr[min]){
			min = j;
			}
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
};
