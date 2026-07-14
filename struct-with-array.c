#include <stdio.h>

struct product{
	int id;
	char name[50];
	float price;
};


int main(){
//dec and ini array sruct elements
	struct product products[3]= {
		{001, "Milk", 23.75},
		{002, "Cereal", 104.35},
		{003, "Flour", 30}
	};

//display elements
	for (int i = 0; i < 3; i++){
		printf("\n-------Item No. %d--------\n", i);
		printf("ID: %d\n", products[i].id);
		printf("Name: %s\n", products[i].name);
		printf("Price: %.2f\n", products[i].price);
	}

	
	return 0; 
}


