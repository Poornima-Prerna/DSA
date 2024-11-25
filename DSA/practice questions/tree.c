#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node *right;
};

struct node* createNode(int data){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct node* insert(struct node* root, int data){
	
//	if(root==NULL){
//		printf("")
//	return createNode(data);

	if (data==-1){
		return NULL;
	}

   printf("\ndata for left node: ",data);
   root->left=insert(root->left,data);
   printf("\ndata for right node",data);
   root->right=insert(root->right,data);
	return root;	
}

int main(){
struct node* root = NULL;

    root = createNode(1);
    printf("%d\n", root->data);
    insert(root, 2);
    insert(root, 4);
    insert(root, -1);
    insert(root, -1);
    insert(root, 5);
    insert(root, -1);
    insert(root, -1);
    insert(root, 3);
    insert(root, 6);
    insert(root, -1);
    insert(root, -1);
    insert(root, 7);
    insert(root, -1);
    insert(root, -1);

}