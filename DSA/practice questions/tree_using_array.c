#include <stdio.h>
#include <stdlib.h>

// Define a maximum size for the array representation of the binary tree
#define MAX_SIZE 100

// Binary tree structure using array representation
int tree[MAX_SIZE];

// Function to insert a node in the binary tree
void insert(int index, int value) {
    if (index < MAX_SIZE) {
        tree[index] = value;
    } else {
        printf("Index out of bounds.\n");
    }
}

// Function to print the tree (in level-order)
void levelOrderTraversal(int n) {
    for (int i = 0; i < n; i++) {
        if (tree[i] != -1) {
            printf("%d ", tree[i]);
        }
    }
    printf("\n");
}

// Function to get the left child index of a node at position i
int leftChild(int i) {
    return 2 * i + 1;
}

// Function to get the right child index of a node at position i
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to perform inorder traversal (not commonly done on arrays but provided for completeness)
void inorderTraversal(int index) {
    if (index >= MAX_SIZE || tree[index] == -1)
        return;
    
    inorderTraversal(leftChild(index));
    printf("%d ", tree[index]);
    inorderTraversal(rightChild(index));
}

// Function to perform pre-order traversal (not commonly done on arrays but provided for completeness)
void preorderTraversal(int index) {
    if (index >= MAX_SIZE || tree[index] == -1)
        return;
    
    printf("%d ", tree[index]);
    preorderTraversal(leftChild(index));
    preorderTraversal(rightChild(index));
}

// Function to perform post-order traversal (not commonly done on arrays but provided for completeness)
void postorderTraversal(int index) {
    if (index >= MAX_SIZE || tree[index] == -1)
        return;
    
    postorderTraversal(leftChild(index));
    postorderTraversal(rightChild(index));
    printf("%d ", tree[index]);
}

int main() {
    // Initialize the binary tree array with a sentinel value (e.g., -1 for empty nodes)
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1; // -1 indicates an empty spot in the array
    }

    // Insert nodes in the tree
    insert(0, 1);  // Root node
    insert(1, 2);  // Left child of root
    insert(2, 3);  // Right child of root
    insert(3, 4);  // Left child of node at index 1
    insert(4, 5);  // Right child of node at index 1
    insert(5, 6);  // Left child of node at index 2
    insert(6, 7);  // Right child of node at index 2

    // Print the tree using level-order traversal
    printf("Level-Order Traversal: ");
    levelOrderTraversal(MAX_SIZE);

    // Print the tree using inorder traversal
    printf("Inorder Traversal: ");
    inorderTraversal(0);
    printf("\n");

    // Print the tree using preorder traversal
    printf("Preorder Traversal: ");
    preorderTraversal(0);
    printf("\n");

    // Print the tree using postorder traversal
    printf("Postorder Traversal: ");
    postorderTraversal(0);
    printf("\n");

    return 0;
}
