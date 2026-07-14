#include <stdio.h>

struct rectangle{
	int length;
	int width;
	int area;
};

int main (){
	
	rectangle rect;
	
	printf("Length and width: ");
	scanf("%d %d", &rect.length, &rect.width);
	
	rect.area = rect.length * rect.width;
	
	printf("The area of the rectangle is %d.", rect.area);
	
	return 0;
}
