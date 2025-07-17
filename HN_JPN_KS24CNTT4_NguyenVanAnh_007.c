//
// Created by Hikari on 17/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Order{
    int id;
    char customer[50];
    int status;
    int total;
}Order;
typedef struct SingleNode{
     Order order;
    struct SingleNode *next;
}SingleNode;
typedef struct DoubleNode{
    Order order;
    struct DoubleNode *next;
    struct DoubleNode *prev;
}DoubleNode;
SingleNode *createNodeSingle(Order order){
    SingleNode *newNode = (SingleNode *)malloc(sizeof(SingleNode));
    newNode -> order = order;
    newNode -> next = NULL;
    return newNode;
}
DoubleNode *createNodeDouble(Order order){
    DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));
    newNode -> order = order;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}
DoubleNode* insertNodeAtEnd(DoubleNode *head, Order order){
DoubleNode *newNode = createNodeDouble(order);
    if(head == NULL){
    head = newNode;
    return head;
    }
    DoubleNode *temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> prev = temp;
    return head;
}
void display(DoubleNode *head) {
    DoubleNode *current = head;
    while(current != NULL) {
        printf("Id: %d\n",current ->order.id);
        printf("Customer: %s\n",current ->order.customer);
        printf("Status: %d\n",current ->order.status == 1 ? 1 : 0);
        printf("Total: %d\n",current ->order.total);
        printf("\n\n");
        current = current -> next;
    }
}
void freeNode (DoubleNode* head) {
    DoubleNode *current;
    while (current != NULL) {
        current = head;
        head = head -> next;
        free(current);
    }
}
DoubleNode* deleteNodeAtEnd(DoubleNode *head, int id) {
    if (head == NULL) {
        return NULL;
    }
    DoubleNode *current = head;
    while (current != NULL) {
        if (current -> order.id == id) {
            if (current -> prev == NULL) {
                head = current -> next;
                if (head != NULL) {
                    head -> prev = NULL;
                }
            } else if ( current -> next == NULL ) {
                current -> prev -> next = NULL;
            } else {
                current -> prev -> next = current -> next;
                current -> next -> prev = current -> prev;
            }
            free(current);
            printf("Deleted completed\n");
            return head;
        }
        current = current -> next;
    }
    printf("Don't found id!\n");
    return head;
}
DoubleNode* updateOrder(DoubleNode *head, int id) {
    DoubleNode *current = head;
    Order order;
    while (current != NULL) {
        if (current -> order.id == id) {
            printf("Enter new customer: ");
            fflush(stdin);
            fgets(current -> order.customer, 50, stdin);
            order.customer[strlen(current -> order.customer) - 1] = '\0';
            printf("Enter new total: ");
            scanf("%d", &current -> order.total);
            printf("Updated succesful\n");
            return head;
        }
        current = current -> next;
    }
    printf("Don't found id!\n");
    return head;
}
DoubleNode* sort(DoubleNode *head) {
    DoubleNode *current = head;
    DoubleNode *prev = NULL;
    while (current != NULL) {
        if (current -> order.total > prev -> order.total) {
            prev = current;
            current = current -> next;
        }
    }
}
// case 7
DoubleNode *foundOderByCustomer(DoubleNode *head, char *key) {
    DoubleNode *current = head;
    int found = 0;
    Order order;
    while (current != NULL) {
        if (strstr(key,current -> order.customer) != NULL) {
            found = 1;
            printf("ID: %d\n", current -> order.id);
            printf("Customer: %s\n", current -> order.customer);
            printf("Total: %d\n", current -> order.total);
            found = 1;
        }
        current = current -> next;
    }
    if (found == 0) {
        printf("Don't found id!\n");
    }
}
int main() {
    int choice;
    int nextId = 1;
    DoubleNode *doubleHead = NULL;
    do{
        printf("1. Add new order\n");
        printf("2. Display order\n");
        printf("3. Deletel Nodes\n");
        printf("4. Update oder\n");
        printf("5. Mark order type\n");
        printf("6. Sort order\n");
        printf("7. Search order\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch(choice){
            case 1:
                Order order;
                order.id = nextId++;
                printf("Enter name of customer: ");
                fgets(order.customer, 50, stdin);
                order.customer [strlen(order.customer) - 1] = '\0';
                printf("Enter status of order: ");
                scanf("%d", &order.status);
                while (getchar() != '\n');
                printf("Enter total number of orders: ");
                scanf("%d", &order.total);
                doubleHead = insertNodeAtEnd(doubleHead, order);
                break;
            case 2:
                display(doubleHead);
                break;
            case 3:
                int deleteById;
                printf("Enter id you want to delete: ");
                scanf("%d", &deleteById);
                doubleHead = deleteNodeAtEnd(doubleHead, deleteById);
                break;
            case 4:
                int updateById;
                printf("Enter id you want to update: ");
                scanf("%d", &updateById);
                doubleHead = updateOrder(doubleHead, updateById);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                char keyCustomer[50];
                printf("Enter name of customer: ");
                fgets(keyCustomer, 50, stdin);
                order.customer[strlen(keyCustomer) - 1] = '\0';
                doubleHead = foundOderByCustomer(doubleHead, keyCustomer);
                break;
            case 8:
                printf("Thank you for using our program.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 8);
    return 0;
}
