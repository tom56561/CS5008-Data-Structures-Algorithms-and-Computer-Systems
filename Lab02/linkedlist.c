// Modify this file
// compile with: gcc linkedlist.c -o linkedlist
// TODO: Po-Shen Lee (Eddie)
// TODO: 25/Jan/2023
// Lab02 CS5008 Spring 2023

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// TODO: Create your node_t type here
typedef struct node
{
	struct node* next;
	int years;
	int wins;
}node_t;

// TODO: Write your functions here
node_t* create_list(int years, int wins, node_t* next){

	node_t* newNode= (node_t*) malloc(sizeof(node_t));
	if(newNode == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
	newNode -> years = years;
	newNode -> wins = wins;
	newNode -> next = next;

	return newNode;
}

void print_list(node_t* head){
	node_t* cur = head;
	while(cur != NULL){
		printf("%d, %d wins\n", cur->years, cur->wins);
		cur = cur->next;
	}
	return;
}

void free_list(node_t* head)
{
   node_t* cur;

   while (head != NULL)
    {
       cur = head;
       head = head->next;
       free(cur);
    }

}



// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.


int main(){
	// TODO: Implement me!  
	// Create a node list
	node_t* head = NULL;
	node_t* newNode;
	newNode = create_list(2014, 71, head);
	head = newNode;
	newNode = create_list(2015, 78, head);
	head = newNode;
	newNode = create_list(2016, 93, head);
	head = newNode;
	newNode = create_list(2017, 93, head);
	head = newNode;
	newNode = create_list(2018, 108, head);
	head = newNode;

	// Print the list
	print_list(head);

	// Free the list
	free_list(head);

	return 0;
}
