#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_DELIVERIES 50

//function declaration
void cityManagement();
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

    while (1){
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
    }
    return 0;
}
void cityManagement() {
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

