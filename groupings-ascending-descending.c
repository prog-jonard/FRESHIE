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
    

    int total = r * c;
    int *temp = malloc(total * sizeof(int));
    

    printf("\nAscending order: \n");
    int flat = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            *(temp + flat++) = *(*(arr + i) + j);
        }
    }
    
    for (int i = 0; i < total - 1; i++){
        for (int j = 0; j < total - i - 1; j++){
            if (*(temp + j) > *(temp + j + 1)){
                int swap = *(temp + j);
                *(temp + j) = *(temp + j + 1);
                *(temp + j + 1) = swap;
            }
        }
    }
    
    for (int i = 0; i < total; i++) {
        printf("%d ", *(temp + i));
    }
    printf("\n");
    

    printf("Descending order: \n");
    flat = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            *(temp + flat++) = *(*(arr + i) + j);
        }
    }
    
    for (int i = 0; i < total - 1; i++){
        for (int j = 0; j < total - i - 1; j++){
            if (*(temp + j) < *(temp + j + 1)){
                int swap = *(temp + j);
                *(temp + j) = *(temp + j + 1);
                *(temp + j + 1) = swap;
            }
        }
    }
    
    for (int i = 0; i < total; i++) {
        printf("%d ", *(temp + i));
    }
    printf("\n");
    

    free(temp);
    for(int i = 0; i < r; i++){
        free(*(arr + i));
    }
    free(arr);
    
    return 0;
}