#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        printf("\nPass %d: Inserting %d\n", i, key);
        
        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            printf("  Shift %d from position %d to %d\n", arr[j], j, j+1);
            arr[j+1] = arr[j];
            j--;
        }
        
        // Insert key in its correct position
        arr[j+1] = key;
        printf("  Inserted %d at position %d\n", key, j+1);
        
        // Print current state
        printf("  Array now: ");
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    insertionSort(arr, n);
    
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}