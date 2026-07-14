#include <stdio.h>

struct complex{
	double real;
	double imagine;
};

int main(){
	
	complex c1 = {.real = 12.45, .imagine = 30.23};
	complex c2 = {.real = 87.64, .imagine = 34.86};
	complex c3 = {.real = 75.72, .imagine = 64.84};
	
	complex sum;
	
	sum.real = c1.real + c2.real + c3.real;
	sum.imagine = c1.imagine + c2.imagine + c3.imagine;
	
	printf("The sum of of the three complex are: %.2lf + %.2lf", sum.real, sum.imagine);
	
	return 0;
}

//find the difference between three complex numbers
//perform subtraction betwen complex numbers by subtracting the complex number from the other complex number and same for the imaginary part
