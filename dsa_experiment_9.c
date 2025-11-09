#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the circular queue

char queue_array[MAX];
int Front = -1;
int Rear = -1;

void insert(char item) {
    // Overflow Condition: Checks if Rear's next position is the same as Front
    if ((Rear + 1) % MAX == Front) {
        printf("Queue Overflow! Cannot insert %c.\n", item);
        return;
    }
    
    // Initial insertion case: Set both Front and Rear to 0
    if (Front == -1) {
        Front = 0;
    }
    
    // Calculate new position for Rear circularly
    Rear = (Rear + 1) % MAX;
    queue_array[Rear] = item;
    printf("Inserted: %c\n", item);
}

void delete() {
    char item_deleted;
    
    // Underflow Condition: Checks if the queue is empty
    if (Front == -1) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    
    item_deleted = queue_array[Front];
    printf("Deleted: %c\n", item_deleted);
    
    // Check if the last element was deleted
    if (Front == Rear) {
        Front = -1;
        Rear = -1;
    } else {
        // Move Front pointer circularly
        Front = (Front + 1) % MAX;
    }
}

void display() {
    int i;
    
    if (Front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue Contents: ");
    
    i = Front;
    // Iterate until the Rear pointer is reached
    while (1) {
        printf("%c ", queue_array[i]);
        if (i == Rear) {
            break;
        }
        // Move pointer circularly
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void check_status() {
    if (Front == -1) {
        printf("Status: Empty (Underflow condition).\n");
    } else if ((Rear + 1) % MAX == Front) {
        printf("Status: Full (Overflow condition).\n");
    } else {
        printf("Status: Operational. Front: %d, Rear: %d\n", Front, Rear);
    }
}

int main() {
    int choice;
    char item;
    
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert Element\n2. Delete Element\n3. Check Status\n4. Display Queue\n5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Clearing buffer.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &item); // Note space before %c
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                check_status();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
