#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node* next;
};

int main(){
	struct node* head = NULL;
	struct node* second = NULL;	
	struct node* third = NULL;
	
	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));	
	third = (struct node *)malloc(sizeof(struct node));	
	
	head->value = 'A';
	head->next = second;
	
	second->value = 'B';
	second->next = third;
	
	third->value = 'C';
	third->next = NULL;
	
	struct node* temp;
	temp = (struct node *)malloc(sizeof(struct node));
	
	temp = head;
	while (temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
//first
	struct node* newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value: ");
	scanf(" %c", &newnode->value);
	newnode->next = head;
	head = newnode;

	temp = head;
	while (temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");	

//last
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value: ");
	scanf(" %c", &newnode->value);
	newnode->next = NULL;
	
	temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newnode;

	temp = head;
	while (temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");	
	
//midol
	int pos;
	int size = 5;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the position you want: ");
	scanf("%d", &pos);
	int i = 0;
	
	if (pos > size){
		printf("Invalid");
	}else{
		temp = head;
		while(i < pos){
			temp = temp->next;
			i++;
		}
		printf("\nInput the data you want to enter: ");
		scanf(" %c", &newnode->value);
		newnode->next = temp->next;
		temp->next = newnode;
	}
	
	temp = head;
	while(temp != NULL){
		printf(" %c", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
	struct node* deleteit;
	deleteit = head;
	head = head->next;
	free(deleteit);
	
	printf("\ndelete the first node: ");
	temp = head;
	while(temp != NULL){
		printf("%c ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
	temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	deleteit = temp->next;
	temp->next = NULL;
	free(deleteit);
	
	printf("\nDelete last element: ");
	temp = head;
	while(temp != NULL ){
		printf("%C ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
	
	return 0;
}