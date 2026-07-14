#include <stdio.h>

//user initialization
void userDefine(int natatae[][3], int rows){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3 ; j ++){
			printf("Input Value: ");
			scanf("%d", &natatae[i][j]);
		}
	}
}

//display elements
void displayElem(int natatae [][3], int rows){
	printf("\n------Matrix: ------\n");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3 ; j ++){
			printf("%d, ", natatae[i][j]);
		}
		printf("\n");
	}
}
	
	//sum of all elements
void findSum(int natatae[][3], int rows){
	int sum = 0;
	printf("\n------SuM ------\n");
	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			sum += natatae[i][j];
		}
	}
	printf("The sum is %d\n", sum);
}

	//finding maximum element
void findMax(int natatae[][3], int rows){
	int max = 0;
	printf("\n------MaX ------\n");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (natatae[i][j] > max){
				max = natatae[i][j];
			}
		}
	}
	printf("The maximum value is %d\n", max);
}

	//finding minimum elements
void findMin(int natatae[][3], int rows){
	int min = natatae[0][0];
	printf("\n------MiN------\n");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (natatae[i][j] < min){
				min = natatae[i][j];
			}
		}
	}
	printf("The minimum value is %d\n", min);
}
	
	//diagonal
void dispDiagonal(int natatae[][3], int rows){
	printf("\n------Diagonal------\n");
	printf("The values are ");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (natatae[i] == natatae[j]){
				
				printf("%d, ", natatae[i][j]);
			}
		}
	}
}

int main(){ //iinside the function and switch case 
int natatae[3][3];

userDefine(natatae, 3);

int choice;

do{
	printf("\n---------MENU-----------\n");
	printf("1. Display Values\n");	
	printf("2. Sum\n");
	printf("3. Maximum\n");
	printf("4. Minimum\n");
	printf("5. Diagonal\n");
	printf("6. Exit\n");
	
	printf("\nI pick: ");
	scanf("%d", &choice);
	
	switch(choice){
	case 1:
		displayElem(natatae, 3);
		break;
	
	case 2:
		findSum(natatae, 3);
		break;
	
	case 3:
		findMax(natatae, 3);
		break;
	
	case 4:
		findMin(natatae, 3);
		break;
	
	case 5:
		dispDiagonal(natatae, 3);
		break;
	
	case 6:
		printf("Exiting....");
		break;
		
	default:
		printf("INVALID CHOICE!");
		break;
	}
	
}while(choice != 6);
		
	return 0;
}

