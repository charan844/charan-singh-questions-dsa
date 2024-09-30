#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertAtFront(struct Node** head_ref, int new_data);
void insertAtEnd(struct Node** head_ref, int new_data);
void insertInOrder(struct Node** head_ref, int new_data);
void deleteFirst(struct Node** head_ref);
void deleteBeforePosition(struct Node** head_ref, int position);
void deleteAfterPosition(struct Node** head_ref, int position);
void traverseList(struct Node* node);

// Function to insert a node at the front of the Linked List
void insertAtFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the Linked List
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

// Function to insert a node in sorted order (ascending)
void insertInOrder(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* current;
    new_node->data = new_data;

    if (*head_ref == NULL || (*head_ref)->data >= new_data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Function to delete the first node of the Linked List
void deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

// Function to delete a node before a specified position
void deleteBeforePosition(struct Node** head_ref, int position) {
    if (position <= 1 || *head_ref == NULL || (*head_ref)->next == NULL) {
        printf("Invalid position or no node to delete before.\n");
        return;
    }

    struct Node* temp = *head_ref;
    if (position == 2) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to delete a node after a specified position
void deleteAfterPosition(struct Node** head_ref, int position) {
    struct Node* temp = *head_ref;

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Function to traverse and print the Linked List
void traverseList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function with menu
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert a node at the front\n");
        printf("2. Insert a node at the end\n");
        printf("3. Insert a node in ascending order\n");
        printf("4. Delete the first node\n");
        printf("5. Delete a node before specified position\n");
        printf("6. Delete a node after specified position\n");
        printf("7. Traverse the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data to insert in ascending order: ");
                scanf("%d", &data);
                insertInOrder(&head, data);
                break;
            case 4:
                deleteFirst(&head);
                break;
            case 5:
                printf("Enter the position before which you want to delete: ");
                scanf("%d", &position);
                deleteBeforePosition(&head, position);
                break;
            case 6:
                printf("Enter the position after which you want to delete: ");
                scanf("%d", &position);
                deleteAfterPosition(&head, position);
                break;
            case 7:
                traverseList(head);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
