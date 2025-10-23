#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define CITY_N_LENTH 50
#define MAX_DELIVERIES 50
#define CITY_FILE "cities.txt"
#define DIST_FILE "distances.txt"

char vehicle_names[3][10] = {"Van", "Truck", "Lorry"};
    int capacity[3] = {1000, 5000, 10000};
    int rate_per_km[3] = {30, 40, 80};
    int speed[3] = {60, 50, 45};
    int fuel_efficiency[3] = {12, 6, 4};
    float fuel_price = 310.0;


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
void loadDistances();
void saveDistances();



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
    int distance[MAX_CITIES][MAX_CITIES];
    char cities[MAX_CITIES][CITY_N_LENTH];
    int count = 0;
    int choice;

    loadCities(cities, &count);
    if (count < 2) {
        printf("At least two cities are needed!\n");
        return;
    }

    loadDistances(distance, count);


        printf("      DISTANCE MANAGEMENT    \n");
        printf("=============================\n");
        printf("1. Input or Edit Distance\n");
        printf("2. View Distance Table\n");
        printf("3. Return to Main Menu\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int i, j, d;
                printf("\nAvailable Cities:\n");
                for (int k = 0; k < count; k++) {
                    printf("%d. %s\n", k + 1, cities[k]);
                }

                printf("Enter source city number: ");
                scanf("%d", &i);
                printf("Enter destination city number: ");
                scanf("%d", &j);

                if (i < 1 || i > count || j < 1 || j > count) {
                    printf("Invalid city numbers!\n");
                    break;
                }

                if (i == j) {
                    printf("Distance from a city to itself is  0 km.\n");
                    distance[i - 1][j - 1] = 0;
                    break;
                }

                printf("Enter distance between %s and %s (in km): ", cities[i - 1], cities[j - 1]);
                scanf("%d", &d);

                distance[i - 1][j - 1] = d;
                distance[j - 1][i - 1] = d;

                saveDistances(distance, count);
                printf("Distance added successfully and saved!\n");
                break;
                }

            case 2: {
                printf("\n%-20s", " ");
                for (int i = 0; i < count; i++) {
                    printf("%-15s", cities[i]);
                }
                printf("\n");

                for (int i = 0; i < count; i++) {
                    printf("%-20s", cities[i]);
                    for (int j = 0; j < count; j++) {
                        printf("%-15d", distance[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            case 3:
                printf("Returning to main menu...\n");
                main();
                return;

            case 4:
                exitProgram();
                return;

            default:
                printf("Invalid choice! Try again.\n");
        }


}
void vehicleInfo(){

    int choice;

    while (1) {
        printf("\n===== VEHICLE INFORMATION =====\n");
        printf("1. View all vehicles\n");
        printf("2. Return to Main Menu\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n=== VEHICLES ===\n");
                printf("Type\tCapacity(kg)\tRate per km(LKR)\tAvg Speed(km/h)\tFuel Efficiency(km/l)\n");
                for (int i = 0; i < 3; i++) {
                    printf("%s\t%d\t\t%d\t\t%d\t\t%d\n",
                           vehicle_names[i],
                           capacity[i],
                           rate_per_km[i],
                           speed[i],
                           fuel_efficiency[i]);
                }
                break;

            case 2:
                printf("\nReturning to main menu...\n");
                main();
                return;
            case 3:
                exitProgram();
                return;

            default:
                printf("Invalid choice! Please enter 1–3.\n");
        }
    }

}
void deliveryRequest(){
 char cities[MAX_CITIES][CITY_N_LENTH];
 int distance[MAX_CITIES][MAX_CITIES];
 int cityCount = 0;

 loadCities(cities, &cityCount);
 loadDistances(distance, cityCount);

 int choice;
 printf("\n===== DELIVERY REQUEST HANDLING =====\n");
        printf("1. New Delivery\n");
        printf("2. Return to Main Menu\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
         switch (choice) {
            case 1: {
                int src, dest, vType;
                float W;

                printf("\nAvailable Cities:\n");
                for (int i = 0; i < cityCount; i++) {
                    printf("%d. %s\n", i + 1, cities[i]);
                }

                printf("\nEnter Source City Number: ");
                scanf("%d", &src);
                printf("Enter Destination City Number: ");
                scanf("%d", &dest);

                if (src < 1 || src > cityCount || dest < 1 || dest > cityCount) {
                    printf("Invalid city numbers!\n");
                    break;
                }
                if (src == dest) {
                         printf("Source and destination cannot be the same!\n");
                    break;
                }

                printf("\nSelect Vehicle Type:\n1. Van\n2. Truck\n3. Lorry\nEnter type: ");
                scanf("%d", &vType);

                if (vType < 1 || vType > 3) {
                    printf("Invalid vehicle type!\n");
                    break;
                }

                printf("Enter Weight (in kg): ");
                scanf("%f", &W);

                if (weight > capacity[vType - 1]) {
                    printf("Weight exceeds capacity of %s (%d kg)!\n",
                           vehicle_names[vType - 1], capacity[vType - 1]);
                    break;
int D = distance[src - 1][dest - 1];
                if (D <= 0) {
                    printf("No valid distance found between %s and %s.\n",
                           cities[src - 1], cities[dest - 1]);
                    break;
                }
float R = rate_per_km[vType - 1];
float S = speed[vType - 1];
float E = fuel_efficiency[vType - 1];

float deliveryCost = D * R * (1 + (W*1/10000));
float fuelUsed = D / E;
float fuelCost = fuelUsed * fuel_price;
float totalCost = deliveryCost + fuelCost;
float profit = deliveryCost * 0.25;
float customerCharge = totalCost + profit;
float timeHrs =D / S;
printf("\n======================================================\n");
                printf("DELIVERY COST ESTIMATION\n");
                printf("------------------------------------------------------\n");
                printf("From: %s\n", cities[src - 1]);
                printf("To: %s\n", cities[dest - 1]);
                printf("Minimum Distance: %d km\n", D);
                printf("Vehicle: %s\n", vehicle_names[vType - 1]);
                printf("Weight: %.0f kg\n", W);
                printf("------------------------------------------------------\n");
                printf("Base Cost: %d × %.0f × (1 + %.0f/10000) = %.2f LKR\n",
                       D, R, W, deliveryCost);
                printf("Fuel Used: %.2f L\n", fuelUsed);
                printf("Fuel Cost: %.2f LKR\n", fuelCost);
                printf("Operational Cost: %.2f LKR\n", totalCost);
                printf("Profit: %.2f LKR\n", profit);
                printf("Customer Charge: %.2f LKR\n", customerCharge);
                printf("Estimated Time: %.2f hours\n", timeHrs);
                printf("======================================================\n");
                break;
            }
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
// Distance management sub functions
void loadDistances(int distance[MAX_CITIES][MAX_CITIES], int cityCount) {
    FILE *fp = fopen(DIST_FILE, "r");
    if (fp == NULL) {
        for (int i = 0; i < cityCount; i++)
            for (int j = 0; j < cityCount; j++)
                distance[i][j] = 0;
        return;
    }

    for (int i = 0; i < cityCount; i++) {
        for (int j = 0; j < cityCount; j++) {
            fscanf(fp, "%d", &distance[i][j]);
        }
    }
    fclose(fp);
}

void saveDistances(int distance[MAX_CITIES][MAX_CITIES], int cityCount) {
    FILE *fp = fopen(DIST_FILE, "w");
    if (fp == NULL) {
        printf("Error saving distances!\n");
        return;
    }

    for (int i = 0; i < cityCount; i++) {
        for (int j = 0; j < cityCount; j++) {
            fprintf(fp, "%d ", distance[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}
