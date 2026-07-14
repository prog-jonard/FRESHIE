#include <stdio.h>

int main (){

int numbers[5] = {23, 52, 60, 19, 70};	
int choice;

do{
	
printf("------Menu----\n");
printf("1. Accessing the Elements\n");
printf("2. Modifying the Elements\n");
printf("3. Taking Input from the User\n");
printf("4. Finding the Sum\n");
printf("5. Finding the Largest Element\n");
printf("6. Exit\n");

printf("Input 1-6: ");
scanf("%d", &choice);
	
	switch(choice){
		case 1:
				//accessing array eleemnts 
			printf("------Accessing the Elements----\n");
				for (int i = 0; i < 5; i++){
				printf("The number %d is: %d.\n", i+1, numbers[i]);
			}
			printf("\n");
			printf("\n");
		break;
		
		case 2:
			//modifying array elements
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
			printf("\n");
			printf("\n");
		break;	
				
		case 3:
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
		break;		
		
		case 4:
			//find sum of the elements 
			printf("------Finding the Sum----\n");
			int sum;
			
			for (int i = 0; i < 5; i++){
				sum = sum + newarray[i];
				}
			printf("The sum is: %d", sum);
			printf("\n");
			printf("\n");
		break;
		
		case 5: {
			//find largest element 
			printf("------Finding the Largest Element----\n");
			int lsum = newarray[0];
			
				for (int i = 1; i < 5; i++){
						if (lsum < newarray[i]){
							lsum = newarray[i];	
						}
				}
			printf("The largest elements is %d\n", lsum);
			
						lsum = numbers[0];
			
				for (int i = 1; i < 5; i++){
						if (lsum < numbers[i]){
							lsum = numbers[i];	
						}
				}
			printf("The largest elements is %d\n", lsum);
		}
		break;
		
		case 6:
			printf("Exit!");
		break;
		
		default:
			printf("Invalid Choice!");
		break;
	}

}while(choice != 6);
	return 0;
}