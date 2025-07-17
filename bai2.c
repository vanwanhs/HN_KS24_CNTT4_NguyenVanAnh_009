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
    Operation operation;
    struct StackBack *top=-1;
    struct StackBack *cap = 0;
};
int main() {
    int choice;
    int choice;
    int nextId = 1;
    DoubleNode *doubleHead = NULL;
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
