#include <stdio.h>
#include <stdlib.h>

// Define a Node of a Doubly Linked List
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// (a) Create a doubly linked list by appending nodes
Node* append(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// (b) Insert a new node to the left of a specific node
Node* insertLeft(Node* head, int target, int data) {
    Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
        return head;
    }
    Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode; // New node becomes the head
    }
    temp->prev = newNode;
    return head;
}

// (c) Delete the node based on a specific value
Node* deleteNode(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
        return head;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // Update head if deleting the first node
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

// Main Function
int main() {
    Node* head = NULL;
    int choice, data, target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a doubly linked list (Append a node)\n");
        printf("2. Insert a node to the left of a specific node\n");
        printf("3. Delete a node by value\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to append: ");
                scanf("%d", &data);
                head = append(head, data);
                break;

            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the target value to insert left of: ");
                scanf("%d", &target);
                head = insertLeft(head, target, data);
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &target);
                head = deleteNode(head, target);
                break;

            case 4:
                displayList(head);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

