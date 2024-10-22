// Menu based program for circular queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if(front == -1 && rear == -1)
        front = rear = 0;
    else if(((rear + 1) % MAX) == front) {
        printf("Queue is full.\n\n");
        return;
    }
    else
        rear = (rear + 1) % MAX;

    queue[rear] = data;
    printf("Inserted %d into the queue.\n\n", data);
}

void dequeue() {
    int data = queue[front];

    if(front == -1 && rear == -1) {
        printf("Queue is empty.\n\n");
        return;
    }
    else if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;

    printf("Deleted %d from the queue.\n\n", data);
}

void display() {
    int i = front;

    if(front == -1 && rear == -1)
        printf("Queue is empty.\n\n");
    else {
        printf("\nQueue: ");

        while(i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d ", queue[rear]);
        printf("\n\n");
    }
}

int main() {
    int choice, data;

    while(1) {
        printf("Menu:\n");
        printf("\t1. Enqueue\n");
        printf("\t2. Dequeue\n");
        printf("\t3. Display\n");
        printf("\t4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        
        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}