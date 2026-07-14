#include <stdio.h>

void displaymenu();
void accessElem(int numbers[]);
void modifElem(int numbers[]);
void takinInput(int newarray[]);
void findSum(int newarray[]);

int main (){
	
	int numbers[5] = {23, 52, 60, 19, 70};	
	int choice;
	
	do{
		displaymenu();
	
	switch(choice);
		case 1;
			accessElem(numbers);
			break;
		
		case 2;
			modfElem(numbers);
			break;
		
		case 3;
			takinInput(newarray);
			break;
		
		case 4;
			findSum(newarray)
			break;
		
		case 5;
		
			break;
		
		case 6;
		
			break;
		
		default
			print("INVALID CHOICE!")
			break;
		
	}while (choice != 6);
	
	return 0;
}

void displaymenu(){
	printf("------Menu----\n");
	printf("1. Accessing the Elements\n");
	printf("2. Modifying the Elements\n");
	printf("3. Taking Input from the User\n");
	printf("4. Finding the Sum\n");
	printf("5. Finding the Largest Element\n");
	printf("6. Exit\n");
}

void accessElem(int numbers[]){
	//accessing array eleemnts 
	printf("------Accessing the Elements----\n");
		for (int i = 0; i < 5; i++){
		printf("The number %d is: %d.\n", i+1, numbers[i]);
	}
}

void modifElem(int numbers[]){
	printf("------Modifying the Elements----\n");
	int slot, value;
	
	printf("Input the number you want to change and its arrangement\n");
		
	printf("For the arrangement in number, pick 1 to 5: ");
	scanf("%d", &slot);
	slot = slot - 1; 
					
	scanf("%d", &value);
	numbers[slot] = value; 
					
	for (int i = 0; i < 5; i++){
	printf("The number %d is: %d.\n", i+1, numbers[i]);
	}
}

void takinInput(int newarray[]){
	//taking input from the user 
printf("newarray");
printf("------Taking Input from the User----\n");
int newarray[5];
			
	for (int i = 0; i < 5; i++){
		printf("Input values for %d: ", i+1);
		scanf("%d", &newarray[i]);
	}
printf("\n");
printf("\n");
	for (int i = 0; i < 5; i++){
	printf("The value of new%d is %d.\n", i+1, newarray[i]);
	}
printf("\n");
printf("\n");
}

void findSum(int newarray[]){
	//find sum of the elements 
printf("------Finding the Sum----\n");
int sum;
			
for (int i = 0; i < 5; i++){
	sum = sum + newarray[i];
	}
printf("The sum is: %d", sum);
}