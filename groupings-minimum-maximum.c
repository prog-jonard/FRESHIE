#include <stdio.h>
#include <stdlib.h>

int main() {
    int **arr, r, c;
    
    printf("Enter rows: \n");
    scanf("%d", &r);
    printf("Enter columns: \n");
    scanf("%d", &c);
    
    arr = malloc(r * sizeof(int *));
    
    for(int i = 0; i < r; i++){
        *(arr + i) = malloc(c * sizeof(int));
    }
    
    printf("Enter values for array: \n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", *(arr + i) + j);
        }
    }
    
    int max = *(*(arr + 0) + 0);
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            int val = *(*(arr + i) + j);
            if (val > max) 
                max = val;
        }
    }
    printf("\nMaximum value: %d\n", max);
    
    int min = *(*(arr + 0) + 0);
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            int val = *(*(arr + i) + j);
            if (val < min) 
                min = val;
        }
    }
    printf("Minimum value: %d\n", min);
    
    
    for(int i = 0; i < r; i++){
        free(*(arr + i));
    }
    free(arr);
    
    return 0;
}