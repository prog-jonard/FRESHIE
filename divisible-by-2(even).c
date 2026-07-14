#include <stdio.h>

void divisible(int numbers[], int size);
	
int main(){
	
	int numbers[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(numbers)/ sizeof(numbers[0]);
	
	divisible(numbers, size);	

	return 0;
}

void divisible(int numbers[], int size){
	for (int i = 0; i  < size; i++)
		if ( numbers[i] % 2 == 0 )
			printf("The number %d is divisible by 2\n", numbers[i]);
}
