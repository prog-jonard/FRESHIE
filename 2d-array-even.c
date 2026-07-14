#include <stdio.h>

void divisible2(int numbers[][3], int rows);
	
int main(){

int numbers[3][3] = {1,2,3,4,5,6,7,8,9};

divisible2(numbers, 3);

return 0;
}

void divisible2(int numbers[][3], int rows){
		for	(int i = 0; i < rows; i++){
			for (int j = 0; j < rows; j++){
				if ( numbers[i][j] % 2 == 0)
				printf("The number %d is divisible by 2.\n", numbers[i][j]);
	        }
		}		    
}
