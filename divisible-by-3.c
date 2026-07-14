#include <stdio.h>

int main (){
	
	void divisible(int arr[],  int  size);
	
	int arr[9] = {1,2,3,4,5,6,7,8,9,};
	int size = sizeof(arr)/ sizeof(arr[0]);
	
	divisible(arr, size);
	
	return 0;
}

void divisible(int arr[], int size){
	for (int  i= 0; i < size; i++){
			if ( arr[i] % 3 == 0)
				printf("the number %d is divisible by 3\n", arr[i]);
		}
}