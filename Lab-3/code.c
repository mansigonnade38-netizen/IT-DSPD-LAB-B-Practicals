// Practical 3 Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of Characters (Array Implementation of Queue with maximum size MAX) a. Insert an Element on to QUEUE b. Delete an Element from QUEUE c. Demonstrate Overflow and Underflow situations on QUEUE d. Display the status of QUEUE e. Exit Support the program with appropriate functions for each of the above operations.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;


void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
    printf("%d enqueued to the queue.\n", value);
    display();
}


void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1; 
    }
    display();
}


void status() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
    } else if (rear == MAX - 1) {
        printf("Queue is Full!\n");
    } else {
        printf("Queue has space. Current size: %d\n", rear - front + 1);
    }
}


int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Status\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                status();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
