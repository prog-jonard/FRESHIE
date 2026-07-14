#include <stdio.h>
#include <stdlib.h>

struct box{
	int value;
	struct box* next;	
};

int main(){
	struct box* isa = NULL;
	struct box* dalawa = NULL;
	struct box* tatlo = NULL;
	
	isa =(struct box *)malloc(sizeof(struct box));
	dalawa =(struct box *)malloc(sizeof(struct box));
	tatlo =(struct box *)malloc(sizeof(struct box));
	
	isa->value = 'A';
	isa->next = dalawa;
			
	dalawa->value = 'B';
	dalawa->next = tatlo;
	
	tatlo->value = 'C';
	tatlo->next = NULL;
	
	struct box* temp = isa;
	while (temp != NULL){
		printf("%c-> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
	struct box* salta;
	salta = (struct box *)malloc(sizeof(struct box));
	printf("\nInput the value: ");
	scanf(" %c", &salta->value);
	salta->next = isa;
	isa =  salta;
	
	temp = isa;
	while (temp != NULL){
		printf("%c-> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
// LAST POS

	salta = (struct box *)malloc(sizeof(struct box));
	printf("Input the value for the last node:");
	scanf(" %c", &salta->value);
	salta->next = NULL;
	
	temp = isa;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = salta;

	//print
	temp = isa;
	while (temp != NULL){
		printf("%c -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	
	return 0;
}