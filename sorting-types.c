#include <stdio.h>

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

void display(int arr[], int size){
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}

void select(int arr[], int sizes){
	for (int i = 0; i < sizes-1; i++){
		int minIdx = i;
		
		for (int j = i+1; j < sizes; j++){
			if (arr[j] < arr[minIdx]){
				minIdx = j;
			}
		}
		if (minIdx != i){
			int temp = arr[i];
			arr[i] = arr[minIdx];
			arr[minIdx] = temp;
		}
	}
}

void insert(int arr[], int sized){
	for (int i = 1; i < sized; i++){
		int key = arr[i], j = i-1;
		
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
	arr[j+1] = key;
	}
	
}

int main (){
	int arr1[] = {5, 4, 3, 2, 1};
	int size = sizeof(arr1)/ sizeof(arr1[0]);
	
	bubblesort(arr1, size);
	
	printf("\nBubble Sort: ");
	display(arr1, size);
	
	int arr2[] = {10, 9, 8, 7, 6};
	int sizes = sizeof(arr2)/ sizeof(arr2[0]);
	
	printf("\n===============================\n");
	select(arr2,sizes);
	printf("Selection Sort: ");
	display(arr2, sizes);
	
	int arr3[] = {10, 8, 6, 4, 2};
	int sized = sizeof(arr3)/ sizeof(arr3[0]);
	
	printf("\n===============================\n");
	insert(arr3, sized);
	printf("Insertion Sorting: ");
	display(arr3, sized);
	
	
	return 0;
}