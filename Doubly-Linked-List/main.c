// Menu based program for singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

void insert_beginning(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
        head->prev = newnode;

    head = newnode;
    printf("Inserted %d at the beginning.\n\n", data);
}

void insert_end(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        struct node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Inserted %d at the end.\n\n", data);
}

void insert_position(int data, int position) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if(position == 1)
        insert_beginning(data);
    else {
        struct node* temp = head;

        for(int i = 1; i < position - 1 && temp != NULL; i++)
            temp = temp->next;

        if(temp == NULL) {
            printf("Position out of bounds.\n\n");
            free(newnode);
            return;
        }

        newnode->next = temp->next;
        newnode->prev = temp;

        if(temp->next != NULL)
            temp->next->prev = newnode;

        temp->next = newnode;
    }

    printf("Inserted %d at the position %d.\n\n", data, position);
}

void delete_beginning() {
    if(head == NULL) {
        printf("List is empty.\n\n");
        return;
    }

    struct node* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    printf("Deleted %d from the beginning.\n\n", temp->data);
    free(temp);
}

void delete_end() {
    if(head == NULL) {
        printf("List is empty.\n\n");
        return;
    }

    struct node* temp = head;

    if(head->next == NULL) {
        printf("Deleted %d from the end.\n\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    printf("Deleted %d from the end.\n\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

void delete_position(int position) {
    if(head == NULL) {
        printf("List is empty.\n\n");
        return;
    }

    struct node* temp = head;

    if(position == 1) {
        delete_beginning();
        return;
    }

    for(int i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Position out of bounds.\n\n");
        return;
    }

    temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted %d from position %d.\n\n", temp->data, position);
    free(temp);
}

void display() {
    if(head == NULL) {
        printf("List is empty.\n\n");
        return;
    }

    struct node* temp = head;
    printf("\n\nLinked List: ");
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n\n");
}

int main() {
    int choice, data, position;

    do {
        printf("Menu:\n");
        printf("\t1. Insert at the beginning\n");
        printf("\t2. Insert at the end\n");
        printf("\t3. Insert at a position\n");
        printf("\t4. Delete from the beginning\n");
        printf("\t5. Delete from the end\n");
        printf("\t6. Delete from a position\n");
        printf("\t7. Display\n");
        printf("\t8. Exit\n\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_beginning(data);
            break;
        
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_end(data);
            break;

        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &position);
            insert_position(data, position);
            break;

        case 4:
            delete_beginning();
            break;

        case 5:
            delete_end();
            break;

        case 6:
            printf("Enter the position: ");
            scanf("%d", &position);
            delete_position(position);
            break;

        case 7:
            display();
            break;

        case 8:
            printf("Exiting...\n");

        default:
            printf("Invalid choice!");
            break;
        }
    } while(choice != 8);
}