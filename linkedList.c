#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFirst(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(struct node** head, int data, int pos) {
    struct node* newNode = createNode(data);
    if (pos == 0) {
        insertAtFirst(head, data);
        return;
    }

    struct node* temp = *head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromFirst(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteFromEnd(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 0) {
        deleteFromFirst(head);
        return;
    }
    struct node* temp = *head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int choice, data, pos;

    while (1) {
    
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete at position\n");
        printf("7. Print list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtFirst(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to inssert: ");
                scanf("%d", &data);
                printf("Enter  position toi insert : ");
                scanf("%d", &pos);
                insertAtPosition(&head, data, pos);
                break;
            case 4:
                deleteFromFirst(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 7:
                printf("Current List: ");
                printList(head);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
