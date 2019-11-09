#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int ptr;
	struct node *next;
	int d;
}Node;

Node* insert(Node *front, Node *newNode){
	Node *ptr= front;
	Node *prev=NULL;
	if(ptr == NULL){
		return newNode;
	}
	while(ptr!=NULL){
		if(newNode->ptr <= ptr->ptr){
			if(ptr == front){
				newNode->next = ptr;
				return newNode;
			}
			newNode->next= ptr;
			prev->next = newNode;
			return front;
		}
		prev = ptr;
		ptr=ptr->next;
	}
	prev->next = newNode;
	return front;
};

Node* delete(Node *front, Node *target){
	Node *ptr = front;
	Node *prev = NULL;
	if(target->ptr == front->ptr){
		front = front->next;
		free(ptr);
		return front;
	}
	while(ptr!=NULL){
		if(ptr->ptr == target->ptr){
			prev->next = ptr->next;
			free(ptr);
			return front;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	return front;
};

void printLL(Node *front){
	Node *ptr = front;
	Node *prev = NULL;
	if(ptr != NULL){
		printf("%d\t", ptr->ptr);
		prev = ptr;
		ptr = ptr->next;
	}
	
	while(ptr != NULL){
		if (prev->ptr != ptr->ptr){
		printf("%d\t", ptr->ptr);}
		prev = ptr;
		ptr = ptr->next;
	}
	return;
};

int count(Node *front){
	Node *ptr = front;
	int i = 0;
	while(ptr != NULL){
		i++;
		ptr = ptr->next;
	}
	return i;
};

void freeLL(Node *front){
	Node *temp;
	while(front != NULL){
		temp = front;
		front = front->next;
		free(temp);
	}
};

int main(int argc, char** argv){
	FILE *input=fopen(argv[1], "r");
	char c;
	int i;
	if(input == NULL){
		printf("%s\n", "error");
		return 0;
	}
	fscanf(input, "%c %d\n", &c, &i);
	Node *front = malloc(sizeof(Node));
	front->d = 1;
	if(c == 'i'){
		front->ptr = i;
		front->next = NULL;
		front->d = 0;
	}
	while(!feof(input)){
		fscanf(input, "%c %d\n", &c, &i);
		Node *temp = malloc(sizeof(Node));
		temp->ptr = i;
		temp->next = NULL;
		if(c == 'i')
			front=insert(front, temp);
		if(c == 'd')
			front=delete(front, temp);
	}
	if(front->d == 1){
		front = delete(front,front);
	}
	printf("%d\n", count(front));
	printLL(front);
	freeLL(front);
	//free(temp);	
	return 0;
};
