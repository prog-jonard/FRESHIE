#include <stdio.h>

int main (){
	
	int a;
	int b;
	int c;
	int temp;
	
	printf("Input three values: ");
	scanf("%d %d %d", &a, &b, &c);
	
	//pataas
	if (a > b){
		temp = b;
		b = a;
		a = temp;
	}
	
	printf("a = %d, b = %d\n", a, b);
	
	if (a > c){
		temp = c;
		c = a;
		a = temp;
	}
	
	printf("a = %d, c = %d\n", a, c);
	
		if (b > c){
		temp = c;
		c = b;
		b = temp;
	}
		printf("a = %d, b = %d, c = %d\n", a, b, c);
	
	printf("Ascending: %d %d %d\n", a, b, c);
	printf("Descending: %d %d %d\n", c, b, a);
	
	return 0;
}

//	if (a > b){    
//		temp = b;
//		b = a;
//		a = temp;

// 1 > 2
// 1 > 3
// 2 > 3 
