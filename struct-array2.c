#include <stdio.h>
//struct employee with id, name and salary
struct Employee{
	int id;
	char name[50];
	float salary;
};

int main(){

struct Employee Emp[10];
int n;
float salary;

//input number of employees
printf("Input number of employee from 1 to 10: ");
scanf("%d", &n);

for(int i = 0; i < n; i++){
	printf("Put information for Employee #%d\n", i+1);
	
	printf("Input ID: ");
	scanf("%d", &Emp[i].id);
	
	printf("Input Name: ");
	scanf(" %[^\n]", Emp[i].name);
	
	printf("Input Salary: ");
	scanf("%f", &Emp[i].salary);
	
	printf("\n");
}


//input threshold value 

//campare salary to threshold
	return 0;
}