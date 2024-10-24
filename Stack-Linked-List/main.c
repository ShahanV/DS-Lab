// Menu based program for stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = 0;
int count = 0;

void push(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = top;
    top = newnode;
    count++;

    printf("%d is pushed into the stack.\n\n", data);
}

void pop() {
    if(top == 0) {
        printf("Stack underflow.\n\n");
        return;
    } else {
        printf("%d is popped.\n\n", top->data);
        top = top->next;
        count--;
    }
}

void display() {
    struct node* temp = top;
    if(top == 0) {
        printf("The stack is empty.\n\n");
        return;
    } else {
        printf("\nStack elements:\n");
        while(temp != 0) {
            printf("\t| %d |\n", temp->data);
            temp = temp->next;
        }

        printf("\t-----");
        printf("\nNumber of nodes in the stack: %d\n\n", count);
    }
}

int main() {
    int choice, data;

    while(1) {
        printf("Menu:\n");
        printf("\t1. Push\n");
        printf("\t2. Pop\n");
        printf("\t3. Display\n");
        printf("\t4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
        
        default:
            printf("Invalid choice.\n\n");
            break;
        }
    }

    return 0;
}