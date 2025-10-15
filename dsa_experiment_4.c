#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d.\n", value);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
    }
    free(temp);
    printf("Deleted from the beginning.\n");
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (head->next == head) {
        head = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
    }
    free(temp);
    printf("Deleted from the end.\n");
}

void deleteGivenElement(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;
    do {
        if (temp->data == value) {
            if (temp == head) {
                deleteFromBeginning();
                return;
            } else {
                prev->next = temp->next;
                free(temp);
                printf("Deleted element %d.\n", value);
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    printf("Element %d not found.\n", value);
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert\n2. Display\n3. Delete from Beginning\n4. Delete from End\n5. Delete Element\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                display();
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                deleteGivenElement(value);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
