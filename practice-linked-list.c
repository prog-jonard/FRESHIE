#include <stdio.h>
#include <stdlib.h>

//node: value stored and pointer to the next node

struct node{
	int value; //stores the character 
	struct node *next; //pointer to the next node
};

int main (){
	//creating the nodes in the main function
	struct node* head = NULL; //head as first, null because no value 
	struct node* second = NULL; //second
	struct node* third = NULL; //third
	
	// allocating the memory for each node 
	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));
	
	// assign data and link the nodes
	head->value= 'A';
	head->next= second;
	
	second->value= 'B';
	second->next= third;
	
	third->value= 'C';
	third->next = NULL;
	
	//printing 
	struct node *temp = head;
	while (temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}	
	printf("NULL");
	
	//new front node
	struct node* newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nInput Value: ");
	scanf("%c", &newnode->value);
	newnode->next = head;
	head = newnode;
	
	temp = head;
	while (temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}	
	printf("NULL");
	
	// last node
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nInput Value for last position: ");
	scanf(" %c", &newnode->value);
	newnode->next = NULL;
	
	temp = head; //traverse
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newnode;
	
	temp = head;               // reset temp back to the beginning
	while (temp != NULL){
	    printf(" %c -> ", temp->value);
	    temp = temp->next;
	}
	printf("NULL\n");

	return 0;	
}
	