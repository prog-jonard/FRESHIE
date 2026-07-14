#include <stdio.h>

void max_min(int arr[3][3]){

	int max = arr[0][0];
	int row; 
	int column;
	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (arr[i][j] > max){
			max = arr[i][j];
			row = i;
			column = j;
			}
		}
	}printf("The max value is %d in position [%d][%d]\n", max, row, column);
}


int main (){
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	max_min(arr);
	
	return 0; 
}