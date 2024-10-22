#include<stdio.h>

void enqueue(int queue[], int val, int n, int* f, int* r) {
    if(*f == 0 && *r == n - 1) {
        printf("Queue is full\n");
        return;
    }
    if(*f == -1 && *r == -1) {
        *f = *r = 0;
    } 
    else if (*f != 0 && *r == n - 1) {
        *r = 0;  // wrap around to 0
    } 
    else {
        *r = *r + 1;  // increment rear
    }
    queue[*r] = val;
}

int dequeue(int queue[], int* front, int* rear, int n) {
    if(*front == -1 && *rear == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int r = queue[*front];  // value to return
    if(*front == *rear) {
        *front = *rear = -1;  // queue becomes empty
    } 
    else {
        *front = (*front + 1) % n;  // increment front
    }
    return r;
}

void display(int queue[], int* front, int* rear, int n) {
    if(*front == -1 && *rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("The queue elements are:\n");
    int i = *front;
    while(i != *rear) {
        printf("%d\t", queue[i]);
        i = (i + 1) % n;
    }
    printf("%d\n", queue[i]);  // print the last element
}

int main() {
    int queue[5];
    int front = -1, rear = -1;
    int choice, value;
    int n = 5;  // size of the queue

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:  // Enqueue
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(queue, value, n, &front, &rear);
            break;

        case 2:  // Dequeue
            {
                int result = dequeue(queue, &front, &rear, n);
                if(result != -1) {
                    printf("Dequeued value: %d\n", result);
                }
            }
            break;

        case 3:  // Display
            display(queue, &front, &rear, n);
            break;

        case 4:  // Exit
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
