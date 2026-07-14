#include <stdio.h>

int main(){
	
	double salary; 
	double newsalary;
	
	printf("Input value for the salary: ");
	scanf("%d", &salary);
	
	double* ptr = &salary;
	
	printf("The salary is %d\n", *ptr);
	
	newsalary = *ptr * 2;
	
	printf("The salary is %d\n", newsalary);
	
	return 0;
}
