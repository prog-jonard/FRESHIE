#include <stdio.h>

void selectsort(int arr[], int n){
	
	for (int i = 0; i < n-1; i++){
		int min_idx = i;
		
		for (int j = i+1; j < n; j++){
			if (arr[j] < arr[min_idx]){
				min_idx = j;
			}
		}
		
		//swapping
		if (min_idx != i){
			int temp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = temp;	
		}	
	}
	
	
}


int main (){
	int arr[] = {5, 4, 3, 2, 1};
	int n = sizeof(arr)/ sizeof(arr[0]);
	
	printf("Original: ");
	for (int i = 0; i < n; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
	
	selectsort(arr, n);
	
	printf("Sorted: ");
	for (int i = 0; i < n; i++){
		printf("%d", arr[i]);
	}
	
	return 0;
}