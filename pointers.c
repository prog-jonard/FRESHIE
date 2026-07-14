#include <stdio.h>

void printing(int arr[], int size){
	for (int i = 0; i < size; i++){
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

void bubblesort(int arr[], int size){
	
	for (int i = 0; i < size-1; i++){
		for (int j = 0; j < size-i-1; j++){
			if (arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
}

void selection(int arr[], int size){
	for (int i = 0; i < size-1; i++){
		int minIdx = i;
		
		for (int j = i+1; j < size; j++)
		
		
		
		
	}
}

int main(){
	int arr1[] = { 5, 4, 3, 2, 1};
	int n = sizeof(arr1)/ sizeof(arr1[0]);
	
	bubblesort(arr1, n);
	printf("Bubble Sort: ");
	printing(arr1, n);
	
	return 0;
}