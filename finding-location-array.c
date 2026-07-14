#include <stdio.h>

void even_finder(int arr[3][3]){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (arr[i][j] % 2 == 0)
			printf("The value %d is even located at [%d][%d]\n", arr[i][j], i, j);
		}
	}
}


int main (){
	int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	even_finder(arr);
	
	return 0;
}