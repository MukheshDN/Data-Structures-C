#include<stdio.h>

int front = -1;
int rear = -1;

void enqueue(int queue[], int val, int n) {
    
    if (rear== n-1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = rear + 1;
    }
    queue[rear] = val;
}

int dequeue(int queue[]) {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
        return -1;
    }
    int val1 = queue[front];
    front++;
    return val1;
}

void display(int queue[]) {
    if (front == -1 && rear == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d \t", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the queue: \n");
    scanf("%d", &n);
    int queue[n];
    
    char ans = 'y';
    while (ans == 'y' || ans == 'Y') {
        int d;
        printf("Enter 1 to add, 2 to delete, 3 to display\n");
        scanf("%d", &d);
        
        if (d == 1) {
            int val1;
            printf("Enter the value to insert: \n");
            scanf("%d", &val1);
            enqueue(queue, val1, n);
        } 
        else if (d == 2) {
            int r1 = dequeue(queue);
            if (r1 != -1) {
                printf("The removed element is %d\n", r1);
            }
        } 
        else if (d == 3) {
            display(queue);
        } 
        else {
            printf("Enter a valid option\n");
        }

        printf("Do you want to continue (y/n)? \n");
        scanf(" %c", &ans); 
    }

    return 0;
}
