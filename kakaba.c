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
	
	struct node* temp = head;
	while(temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");

//first
	struct node* newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nInput the value you want: ");
	scanf(" %c", &newnode->value);
	newnode->next = head;
	head = newnode;
	
	temp = head;
	while(temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
//last 
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nInput the value you want: ");
	scanf(" %c", &newnode->value);
	newnode->next = NULL;
	
	temp = head;
	while(temp->next != NULL){
		temp = temp->next;		
	}
	temp->next = newnode;
	
	temp = head;
	while(temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
//based on wanted position
	int pos;
	int size = 5;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nInput the position you want: ");
	scanf("%d", &pos);
	int i = 0;
	
	if (pos > size){
		printf("Position is Invalid.");
	}else{
		temp = head;
		while (i < pos){
			temp = temp->next;
			i++;
		}
		printf("\nEnter the value you want: ");
		scanf(" %c", &newnode->value);
		newnode->next = temp->next;
		temp->next = newnode;
	}
	
		temp = head;
	while(temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
//delete first 
	struct node* deletethis;
	deletethis = head;
	head = head->next;
	free(deletethis);
	
	printf("\nDelete first element: ");
	temp = head;
	while (temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
	temp = head;
	while (temp->next->next != NULL){
		temp = temp->next;
	}
	deletethis = temp->next;
	temp->next = NULL;
	free(deletethis);
	
//last element
	printf("\nDelete last element: ");
	temp = head;
	while(temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
//wanted position
	printf("\nEnter the index position you want to delete: ");
	scanf("%d", &pos);
	
	temp = head;
	for (int i = 0; i < (pos - 1); i++){
		temp = temp->next;
	}
	deletethis = temp->next;
	temp->next = deletethis->next;
	free(deletethis);
	
	printf("\nDelete the element at position: ");
	temp = head;
	while(temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
	return 0;	
}