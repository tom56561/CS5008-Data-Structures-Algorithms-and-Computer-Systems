// Name: Po-Shen Lee
// Date: Mar 29
//
// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
    bst_t* myBST = (bst_t*)malloc(sizeof(bst_t));
    myBST->size = 0;
    myBST->root = NULL;
    return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
    return t->size == 0;
}

// Adds a new node containg item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
int bst_add(bst_t* t, int item){
    bstnode_t* new_node = (bstnode_t*)malloc(sizeof(bstnode_t));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = item;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;

    if (t->root == NULL) {
        t->root = new_node;
    } else {
        bstnode_t* current = t->root;
        bstnode_t* parent = NULL;

        while (current != NULL) {
            parent = current;
            if (item <= current->data) {
                current = current->leftChild;
            } else {
                current = current->rightChild;
            }
        }

        if (item <= parent->data) {
            parent->leftChild = new_node;
        } else {
            parent->rightChild = new_node;
        }
    }

    t->size++;
    return 1;
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// A BST that is NULL should print "(NULL)"
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
    if (t->root == NULL) {
        printf("(NULL)\n");
        return;
    }

    if (order == 0) {
        // Print in ascending order
        bstnode_t* stack[t->size];
        int top = -1;
        bstnode_t* current = t->root;

        while (current != NULL || top >= 0) {
            while (current != NULL) {
                stack[++top] = current;
                current = current->leftChild;
            }

            current = stack[top--];
            printf("%d ", current->data);

            current = current->rightChild;
        }
    } else {
        // Print in descending order
        bstnode_t* stack[t->size];
        int top = -1;
        bstnode_t* current = t->root;

        while (current != NULL || top >= 0) {
            while (current != NULL) {
                stack[++top] = current;
                current = current->rightChild;
            }

            current = stack[top--];
            printf("%d ", current->data);

            current = current->leftChild;
        }
    }
    printf("\n");
}

// Returns the sum of all the nodes in the bst. 
// A BST that is NULL exits the program.
// It should run in O(n) time.
int bst_sum(bst_t *t){
  int sum = 0;
    bstnode_t* stack[t->size];
    int top = -1;
    bstnode_t* current = t->root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->leftChild;
        }

        current = stack[top--];
        sum += current->data;

        current = current->rightChild;
    }

    return sum;
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree -- exit the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){
  bstnode_t* current = t->root;

    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }

        if (value < current->data) {
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }
    }

    return 0;
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
    return t->size;
}

//Free BST helper function
void bst_free_helper(bstnode_t* node) {
    if (node == NULL) {
        return;
    }

    bst_free_helper(node->leftChild);
    bst_free_helper(node->rightChild);
    free(node);
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){
    bst_free_helper(t->root);
    free(t);
}

