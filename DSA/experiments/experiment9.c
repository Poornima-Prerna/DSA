#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*createNode(int data){
    struct node*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    //if(newnode==NULL){
        //printf("Memory is not allocated");
    //}
    //else{
      //  printf("Memory is allocated");
    //}
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insert(struct node* root,int data){
    struct node* temp;
    if(root==NULL){
        temp=createNode(data);
        return temp;
    }
    else if(data<root->data){
        root->left = insert(root->left,data);
    }
   else if(data>root->data){
        root->right = insert(root->right,data);
    }
    return root;
}
struct node* search(struct node*root,int data){
        if(root==NULL){
            return 0;
        }
        else if(root->data==data){
            return root;
        }
        else if(data<root->data)
        {
            return  search(root->left,data);
        }
        else if(data>root->data){
            return search(root->right,data);
        }
    }
        int main()
        {
            struct node*root=NULL;
            root = insert(root,50);
            root = insert(root,30);
            root = insert(root,20);
            root = insert(root,40);
            root = insert(root,70);
            root = insert(root,60);
            root = insert(root,80);
            //search for a value
            int data = 90;
            if(search(root,data)){
                printf("Node with value %d found in the BST \n",data);
            }
            else {
                    printf("Node with value %d not found in the BST \n",data);
                }
        }