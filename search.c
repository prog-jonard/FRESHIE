#include <stdio.h>

void bubblesort(int aayusin[], int size){

	for (int i = 0; i < size-1; i++){
		for (int j = 0; j < size-i-1; j++){
			if (aayusin[j] > aayusin[j+1]){
				int temp = aayusin[j];
				aayusin[j] = aayusin [j+1];
				aayusin[j+1] = temp;
		}
	}	
}
}


int main (){
	
	int aayusin[] = {2, 6, 5, 9, 4, 7};
	int size = sizeof(aayusin)/ sizeof(aayusin[0]);
	
	    // Print original
    printf("Original: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", aayusin[i]);
    }
	
	bubblesort(aayusin, size);
	
	printf("\nSorted:   ");
    for (int i = 0; i < size; i++) {
        printf("%d ", aayusin[i]);
    }
    
    printf("\nYey, ang galing :0 ");
	
	
	
	return 0;
}