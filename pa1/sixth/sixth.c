#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int ptr;
	struct node* left;
	struct node* right;

}Node;

Node* insert(Node* root, int i){

	if(root == NULL){
		Node *temp = malloc(sizeof(Node));
     	   	temp->ptr = i;
        	temp->left = NULL;
	        temp->right = NULL;
		return temp;
	}
	if (i < root->ptr)
		root->left = insert(root->left,i);
	else if(i > root->ptr)
		root->right = insert(root->right,i);
	
	return root;
};

void printBST(Node* root){
	if(root==NULL){
		return;
	}
	printBST(root->left);
        printf("%d\t", root->ptr);
        printBST(root->right);
};

void freeBST(Node* root){
	if(root){
		freeBST(root->left);
		freeBST(root->right);
		free(root);
	}
};

int main(int argc, char** argv){
	FILE *input = fopen(argv[1], "r");

	if(input == NULL){
		printf("error");
		return 0;
	}
	
	char c;
	int i;
	
	fscanf(input, "%c %d\n",&c,&i);
	Node* root = malloc(sizeof(Node));
	//if(c=='i'){
		root->ptr = i;
		root->left = NULL;
		root->right = NULL;
		while(!feof(input)){
			//printf("\nbreak");
                	fscanf(input, "%c %d\n",&c,&i);
    	      	        if(c == 'i'){
        	                insert(root, i);
				//printf("break\n");
                	}
        }
	//}else{
	//	printf("error");
	//	return 0;
	//}
	printBST(root);
	freeBST(root);
	fclose(input);
	return 0;
};
