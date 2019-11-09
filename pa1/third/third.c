#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int ptr;
	struct node* next;
}Node;

int hash (int key){
	int result;
	result = key % 10000;

	if(result < 0)
		result = result + 10000;
	return result;
};

int insert(Node** hashTable, Node* newNode){//returns 1 if collision occurs 0 if no collision
	int collision = 0;
	int index = hash(newNode->ptr);

	Node* front = *(hashTable+index);
	//printf("%d\n", index);
	if(front == NULL){
		*(hashTable+index) = newNode;
		collision = 0;
		//printf("%d\n", newNode->ptr);
	}else{
		Node* ptr = front;
		while(ptr!=NULL){
			if(ptr->ptr == newNode->ptr){
				collision = 1;
				break;
			}
			ptr = ptr->next;
		//	printf("%d\n", ptr->ptr);
		}
		if(collision == 0){
			newNode->next = front;
			*(hashTable+index) = newNode;
			collision = 1;
		}

	}

	return collision;
};

int search(Node** hashTable, int target){// returns 1 if it found target and 0 if it didnt find target
	int success =0;

	int index = hash(target);

	Node* ptr = *(hashTable+index);


	while(ptr != NULL){
		if(ptr->ptr == target){
			success = 1;
			//printf("found");
			break;

		}

		ptr = ptr->next;
	}

	return success;
};

void freeLinkedList(Node* front){
//	Node* ptr = front;
	if(front != NULL){
		Node* ptr = front;
		while(ptr != NULL){
			Node* temp = ptr;
			ptr = ptr->next;
			free(temp);

		}

	}

};

void freeHash(Node** hashTable){
	int i;
	for(i=0; i < 10000; i++){
		Node* ptr = *(hashTable+i);
		freeLinkedList(ptr);
	}

};



int main(int argc, char* argv[]){

	FILE *input = fopen(argv[1], "r");

	Node **hashptr = malloc(10000*sizeof(Node*));
	Node **hashTable = hashptr;

	int i;
	for(i=0; i < 10000;i++){
		*hashptr = NULL;
		hashptr++;

	}

	char c;
	int n;
	int collisions=0;
	int succSearches=0;
	int searchResult,insertResult;

	while(!feof(input)){
		fscanf(input, "%c %d\n", &c, &n);
		if(c=='i'){
			Node* temp= malloc(sizeof(Node));
			temp->ptr = n;
			temp->next = NULL;

			insertResult = insert(hashTable, temp);
			if(insertResult == 1){
				collisions++;}

		}
		if(c=='s'){
			searchResult = search(hashTable, n);
//			printf("\t%d\n", searchResult);
			if(searchResult > 0){
				succSearches++;
			}
		}

	}

	printf("%d\n", collisions);
	printf("%d", succSearches);
	freeHash(hashTable);
	//free(hashptr);
	free(hashTable);

	return 0;
}
