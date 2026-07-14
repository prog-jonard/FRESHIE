#include <stdio.h>

//struct with: roll no, name, mark for 3subjects, grade, for each students
struct STUDENTS{
	int roll_no;
	char name[50];
	float mark[3];
	char grade;
};

int main(){
	
	struct STUDENTS student[5];
	
//input data for 5 students 
printf("\n--------STUDENTS---------\n");
printf("Input data for student\n");
for (int i = 0; i < 5; i++){
	printf("Roll Number for student %d\n", i+1);
	scanf("%d", &student[i].roll_no);
//name
	printf("Enter name for student %d\n", i+1);
	scanf(" %[^\n]", student[i].name);
//mark 
	printf("Input 3 Grades for Each Mark\n");	
	for(int j = 0; j < 3; j++){
		scanf("%f, ", &student[i].mark[j]);
	}
	
	float ave = (student[i].mark[0] + student[i].mark[2] + student[i].mark[3]) /3;
	if (ave >= 90){
		student[i].grade = 'A';
	}else if (ave >= 80){
		student[i].grade = 'B';
	}else if (ave >= 70){
		student[i].grade = 'C';
	}else if (ave >= 60){
		student[i].grade = 'D';
	}else{
		student[i].grade = 'F';
	}
}

    printf("\n========= STUDENT REPORT =========\n");
    for(int i = 0; i < 5; i++) {
        printf("\nRoll No: %d\n", student[i].roll_no);
        printf("Name: %s\n", student[i].name);
        printf("Marks: %.2f, %.2f, %.2f\n", 
               student[i].mark[0], student[i].mark[1], student[i].mark[2]);
        printf("Grade: %c\n", student[i].grade);
        printf("--------------------------------\n");
    }


//calculate average and assign grade 



//display all students 	
	
	
	
	return 0;
}