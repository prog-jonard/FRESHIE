#include <stdio.h>

void divisible3(int numbers[][3], int rows);
	
int main(){
	
	int numbers[3][3] = {1,2,3,4,5,6,7,8,9};
	
	divisible3( numbers, 3);
	
	return 0;
}

void divisible3( int numbers[][3], int rows){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < 3; j++){
			if ( numbers[i][j] % 3 == 0)
				printf("The number %d is divisible by 3.\n", numbers[i][j]);
		}
	}
}
