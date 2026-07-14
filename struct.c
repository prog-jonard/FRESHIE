#include <stdio.h>
#include <string.h>

struct students{
	char name[50]; 
	int age;
	float gpa;
	char section[50];
};

int main(){
//create struct variable
	struct students s1, s2;
	
	
//assign values
strcpy(s1.name, "Totoy");
s1.age = 15;
s1.gpa = 2;
strcpy(s1.section, "Gumamela");
 
strcpy(s2.name, "Aika");
s2.age = 15;
s2.gpa = 1.5;
strcpy(s2.section, "Gumamela");

printf("\n---------ID----------\n");
printf("Name: %s\n", s1.name);
printf("Age: %d\n", s1.age);
printf("GPA: %.2f\n", s1.gpa);
printf("Section: %s\n", s1.section);

printf("\n---------ID----------\n");
printf("Name: %s\n", s2.name);
printf("Age: %d\n", s2.age);
printf("GPA: %.2f\n", s2.gpa);
printf("Section: %s\n", s2.section);

//display values
	
	return 0;
}