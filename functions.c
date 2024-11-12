#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

Node* concat(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

Node* sort(Node* head) {
    if (head == NULL) return head;
    Node *temp, *current;
    int t;
    current = head;
    while (current != NULL) {
        temp = head;
        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return head;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* temp = head;
    Node* next;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

void displayList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int choice, value;

    while (true) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning in List 1\n");
        printf("2. Insert at beginning in List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Sort List 2\n");
        printf("5. Concatenate List 2 to List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Display Lists\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert in List 1: ");
                scanf("%d", &value);
                list1 = insertAtBeginning(list1, value);
                break;
            case 2:
                printf("Enter value to insert in List 2: ");
                scanf("%d", &value);
                list2 = insertAtBeginning(list2, value);
                break;
            case 3:
                list1 = sort(list1);
                printf("List 1 sorted.\n");
                break;
            case 4:
                list2 = sort(list2);
                printf("List 2 sorted.\n");
                break;
            case 5:
                list1 = concat(list1, list2);
                list2 = NULL; // List 2 is now part of List 1, so clear List 2
                printf("Lists concatenated (List 2 into List 1).\n");
                break;
            case 6:
                list1 = reverse(list1);
                printf("List 1 reversed.\n");
                break;
            case 7:
                printf("List 1: ");
                displayList(list1);
                printf("List 2: ");
                displayList(list2);
                break;
            case 8:
                printf("Exiting program.\n");
                freeList(list1);
                freeList(list2);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
