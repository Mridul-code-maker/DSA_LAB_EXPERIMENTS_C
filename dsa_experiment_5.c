#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
    char *name;
    int date;
    char *activity;
};

struct Day* calendar = NULL;

void create() {
    // Dynamically allocate array for 7 days
    calendar = (struct Day*)malloc(7 * sizeof(struct Day));
    if (calendar == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

void read() {
    char tempName[50], tempActivity[100];
    for (int i = 0; i < 7; i++) {
        printf("\nEnter name of day %d: ", i + 1);
        scanf(" %[^\n]", tempName); // Note the space to handle newline char
        
        // Dynamically allocate memory for Day Name
        calendar[i].name = (char*)malloc(strlen(tempName) + 1);
        strcpy(calendar[i].name, tempName);

        printf("Enter date for %s: ", calendar[i].name);
        scanf("%d", &calendar[i].date);

        printf("Enter activity for %s: ", calendar[i].name);
        scanf(" %[^\n]", tempActivity); // Note the space
        
        // Dynamically allocate memory for Activity Description
        calendar[i].activity = (char*)malloc(strlen(tempActivity) + 1);
        strcpy(calendar[i].activity, tempActivity);
    }
}

void display() {
    printf("\n--- Weekly Activity Report ---\n");
    for (int i = 0; i < 7; i++) {
        printf("Day: %s\n", calendar[i].name);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n\n", calendar[i].activity);
    }
}

void freeMemory() {
    // Free allocated memory for strings inside each structure
    for (int i = 0; i < 7; i++) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }
    // Free the main array of structures
    free(calendar);
}

int main() {
    create();
    read();
    display();
    freeMemory();
    return 0;
}
