#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning
void insertFront(int data) {
    struct Node* new_node = newNode(data);
    new_node->next = head;
    if (head != NULL)
        head->prev = new_node;
    head = new_node;
}

// Function to insert a new node at the end
void insertEnd(int data) {
    struct Node* new_node = newNode(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct Node* last = head;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

// Function to delete a node from the beginning
void deleteFront() {
    if (head == NULL)
        return;
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

// Function to delete a node from the end
void deleteEnd() {
    if (head == NULL)
        return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* last = head;
    while (last->next != NULL)
        last = last->next;
    last->prev->next = NULL;
    free(last);
}

// Function to search an element in the list
struct Node* search(int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Function to print the list in forward direction
void printListForward() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the list in reverse direction
void printListReverse() {
    struct Node* temp = head;
    if (temp == NULL)
        return;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    insertFront(10);
    insertFront(20);
    insertEnd(30);
    insertEnd(40);

    printf("Forward: ");
    printListForward();

    printf("Reverse: ");
    printListReverse();

    deleteFront();
    deleteEnd();

    printf("After deletion: ");
    printListForward();

    return 0;
}