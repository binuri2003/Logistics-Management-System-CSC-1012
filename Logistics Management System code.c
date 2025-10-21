#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define CITY_N_LENTH 50
#define MAX_DELIVERIES 50
#define CITY_FILE "cities.txt"


//function declaration
void cityManagement();
void addCity();
void renameCity();
void removeCity();
void viewCities();
void loadCities();
void saveCities();
void distanceManagement();
void vehicleInfo();
void deliveryRequest();
void viewDeliveries();
void routeFinder();
void reports();
void help();
void save();
void exitProgram();



int main()
{

    int choice;


    printf("==============================\n");
    printf("LOGISTICS MANAGEMENT SYSTEM\n");
    printf("==============================\n");
    printf("1. City Management\n");
    printf("2. Distance Management\n");
    printf("3. Vehicle Information\n");
    printf("4. Delivery Request\n");
    printf("5. View All Deliveries\n");
    printf("6. Route Finder\n");
    printf("7. Reports\n");
    printf("8. Help\n");
    printf("9. Save\n");
    printf("10. Exit\n");

    printf("Enter your Choice (1-10):\n");
    scanf("%d",&choice);

    switch(choice){
            case 1:
                cityManagement();
            break;
            case 2:
                distanceManagement();
             break;
            case 3:
                 vehicleInfo();
            break;
            case 4:
                deliveryRequest();
             break;
            case 5:
                viewDeliveries();
             break;
            case 6:
                routeFinder();
            break;
            case 7:
                reports();
             break;
            case 8: help();
             break;
             case 9:
                save();
             break;
            case 10:
                exitProgram();
                return 0;

             break;
            default:
                 printf("Invalid choice!\n");
}

    return 0;
}
void cityManagement() {
    int choice;
    int count=0;
    char cities[MAX_CITIES][CITY_N_LENTH];
    loadCities(cities, &count);

        printf("\nCITY MANAGEMENT\n");
        printf("\n==========================\n");
        printf("1. Add City\n");
        printf("2. Rename City\n");
        printf("3. Remove City\n");
        printf("4. View All Cities\n");
        printf("5. Return to Main Menu\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

         switch (choice) {
            case 1:
                addCity(cities, &count);
                break;
            case 2:
                renameCity(cities, count);
                break;
            case 3:
                removeCity(cities, &count);
                break;
            case 4:
                viewCities(cities, count);
                break;
            case 5:
                saveCities(cities, count);
                printf("Returning to main menu...\n");
                main();
                break;
              case 6:
                exitProgram();
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }


}

void distanceManagement(){
}
void vehicleInfo(){
}
void deliveryRequest(){
}
void viewDeliveries(){
}
void routeFinder(){
}
void reports(){
}
void help(){
}
void save(){
}
void exitProgram(){
    char choice;


        printf("\nAre you sure you want to exit? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y')
        {
            printf("\nExiting program...\n");
            exit(0);
        }
        else if (choice == 'N' || choice == 'n')
        {
            printf("\nReturning to main menu...\n");
            main();
        }
        else
        {
            printf("Invalid input! Please enter Y or N.\n");
        }
    }
//cityManagement function's sub function
void loadCities(char cities[][CITY_N_LENTH],int *count){
    FILE *fp = fopen(CITY_FILE,"r");
    if (fp==NULL)return;

    while (fgets(cities[*count], CITY_N_LENTH, fp)) {
        cities[*count][strcspn(cities[*count], "\n")] = '\0';
        (*count)++;
    }
    fclose(fp);
}


void saveCities(char cities[][CITY_N_LENTH],int count){
    FILE *fp = fopen(CITY_FILE, "w");
    if (fp == NULL) {
        printf("SAVING ERROR!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", cities[i]);
    }
    fclose(fp);
}
void addCity(char cities[][CITY_N_LENTH], int *count) {
    if (*count >= MAX_CITIES) {
        printf("LIMIT EXCEEDED (MAX %d)!\n", MAX_CITIES);
        return;
    }

    printf("Enter new city name: ");


    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }


    if (fgets(cities[*count], CITY_N_LENTH, stdin) == NULL) {
        printf("Input error!\n");
        return;
    }

    cities[*count][strcspn(cities[*count], "\n")] = '\0';

    (*count)++;
    saveCities(cities, *count);
    printf("City added successfully!\n");
}


void renameCity(char cities[][CITY_N_LENTH],int count){
     if (count == 0) {
        printf("No cities available!.\n");
        return;
     }
        viewCities(cities, count);

    int index;

    printf("Enter city number to rename: ");
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("Invalid Index!\n");
        return;
    }

    printf("Enter new city name: ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    fgets(cities[index - 1], CITY_N_LENTH, stdin);
    cities[index - 1][strcspn(cities[index - 1], "\n")] = '\0';

    saveCities(cities, count);
    printf("City renamed successfully!\n");

}
void removeCity(char cities[][CITY_N_LENTH],int *count){
  if (*count == 0) {
        printf("No cities available!.\n");
        return;
  }

       viewCities(cities,*count);
       int index;
       printf("Enter city number to remove: ");
       scanf("%d", &index);

    if (index < 1 || index > *count) {
        printf("Invalid number!\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        strcpy(cities[i], cities[i + 1]);
    }
    (*count)--;

    saveCities(cities, *count);
    printf("City removed successfully!\n");
}

void viewCities(char cities[][CITY_N_LENTH],int count){
    if (count == 0) {
        printf("No cities available!.\n");
        return;
    }

    printf("\n====List of Cities====\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, cities[i]);
    }
}

