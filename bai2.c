//
// Created by Hikari on 17/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
typedef struct Operation {
    char url[1000];
    char time[100];
}Operation;
typedef struct StackBack {
    Operation data[100];
   int top;
   int capacity;
    int front;
};
int main() {
    int choice;
    do{
        printf("1. VISIT url\n");
        printf("2. BACKWARD\n");
        printf("3. FORWARD\n");
        printf("4. CURRENT\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch(choice){
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                printf("Thank you for using our program.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 5);
    return 0;
}
