#include <stdio.h>
#include <stdlib.h>

int main (){
	
	struct node
	{
	char value;	
	struct node* nextnodeaddress;
	};
	
	struct node *current, *head, *tail;
	
	current = NULL;
	head = NULL;
	tail = NULL;
	
	//creating node 1
	current = (struct node*)malloc(sizeof(struct node));
	current->value = 'A';
	current->nextnodeaddress = NULL;
	head = current;
	tail = current;
	
	current = (struct node*)malloc(sizeof(struct node));
	current->value = 'B';
	current->nextnodeaddress = NULL;
	head->nextnodeaddress = current;
	tail = current;
	
	current = (struct node*)malloc(sizeof(struct node));
	current->value = 'C';
	current->nextnodeaddress = NULL;
	tail->nextnodeaddress = current;
	tail = current;
	
	struct node* temp = head;
	while (temp != NULL){
			printf("%c ", temp->value);
			temp = temp->nextnodeaddress;
	}

	return 0;
}