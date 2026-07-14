#include <stdio.h>

void displayVehicles(struct Vehicle vehicle[], int size);
void Displayhigherthan500(struct Vehicle vehicle[], int size);
void saveFile(struct Vehicle vehicle[], int size);
void loadFile(struct Vehicle vehicle[], int size);

struct ServiceRecords{
	char date[10];	
	float serviceCost;
};

struct Vehicle{
	char platenumber[10];
	char ownername[10];
	char servicetype[10];
	struct ServiceRecords record;
};

int main(){
	struct Vehicle vehicle[5];
	printf("\n===ENTER DETAILS===\n");
	for(int i = 0; i < 5; i++){
		printf("Details for Driver No.%d\n", i+1);
		printf("Plate Number: ");
		scanf(" %[^\n]", vehicle[i].platenumber);
		printf("Name: ");
		scanf(" %[^\n]", vehicle[i].ownername);
		printf("Service Type: ");
		scanf(" %[^\n]", vehicle[i].servicetype);
		printf("Date: ");
		scanf(" %[^\n]", vehicle[i].record.date);
		printf("Service Cost: ");
		scanf(" %f", &vehicle[i].record.serviceCost);
	}
	
	displayVehicles(vehicle, 5);
	Displayhigherthan500(vehicle, 5);
	saveFile(vehicle, 5);
	
	struct Vehicle member[5];
	int loadedcount = 0;
	
	if (loadedcount < 0){
		printf("\n====LOADED RECORDS====\n");
		displayVehicles(member, loadedcount);
	}
	
	return 0;
}

void displayVehicles(struct Vehicle vehicle[], int size){
	printf("\n=====DISPLAY MENU=====\n");
	for (int i =0; i < size; i++){
		printf("\nDetails for Driver No. %d\n", i+1);
		printf("Plate Number: %s\n", vehicle[i].platenumber);
		printf("Name: %s\n", vehicle[i].ownername);
		printf("Service Type: %s\n", vehicle[i].servicetype);
		printf("Date: %s\n", vehicle[i].record.date);
		printf("Service Cost: %.2f\n", vehicle[i].record.serviceCost);
	}	
}

void Displayhigherthan500(struct Vehicle vehicle[], int size){
	printf("\n=====HIGHER THAN 500=====\n");
	
	int found = 0;
	
	for(int i = 0; i < size; i++){
		if (vehicle[i].record.serviceCost > 500){
			printf("Id: Number | Name | S.Type | Date | S.Cost\n");
			printf("Id: %s | %s | %s | %s | %.2f\n", 
			vehicle[i].platenumber,
			vehicle[i].ownername,
			vehicle[i].servicetype,
			vehicle[i].record.date, 
			vehicle[i].record.serviceCost );
			
			found = 1;
		}
	}
	
	if (!found){
		printf("No higher than 500");
	}
	
}

void saveFile(struct Vehicle vehicle[], int size){
	FILE *fp = fopen("vehicle.txt", "w");
	
	if(fp == NULL){
		printf("Saving Error!");
		return;
	}
	
	fprintf(fp, "%d\n", size);
	
		for (int i =0; i < size; i++){
		fprintf(fp, "%s\n", vehicle[i].platenumber);
		fprintf(fp, "%s\n", vehicle[i].ownername);
		fprintf(fp, "%s\n", vehicle[i].servicetype);
		fprintf(fp, "%s\n", vehicle[i].record.date);
		fprintf(fp, "%f\n", vehicle[i].record.serviceCost);
	}
	
	fclose(fp);
	printf("Saving Sucess %d file!", size);
}

void loadFile(struct Vehicle vehicle[], int size){
	FILE *fp = fopen("vehicle.txt", "w");
	
	if(fp == NULL){
		printf("Saving Error!");
		return;
	}
	
	fprintf(fp, "%d\n", size);
	
		for (int i =0; i < size; i++){
		fscanf(fp, "%[^\n]\n", vehicle[i].platenumber);
		fscanf(fp, "%[^\n]\n", vehicle[i].ownername);
		fscanf(fp, "%[^\n]\n", vehicle[i].servicetype);
		fscanf(fp, "%[^\n]\n", vehicle[i].record.date);
		fscanf(fp, "%[^\n]\n", &vehicle[i].record.serviceCost);
	} 
	
	fclose(fp);
	printf("Saving Sucess %d file!", size);
}