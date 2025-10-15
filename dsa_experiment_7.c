#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAX_SIZE 100

// --- Global Integer Stack (The one that needs protection) ---
int stack_arr[MAX_SIZE];
int stack_top = -1;

void push_element(int val) {
    if (stack_top == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push %d.\n", val);
    } else {
        stack_arr[++stack_top] = val;
        printf("Pushed %d onto stack.\n", val);
    }
}

void pop_element() {
    if (stack_top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        printf("Popped %d from stack.\n", stack_arr[stack_top--]);
    }
}

void display_status() {
    if (stack_top == -1) {
        printf("Stack is currently empty.\n");
    } else {
        printf("Stack contents (TOP to BOTTOM):\n");
        for (int i = stack_top; i >= 0; i--) {
            printf("| %d |\n", stack_arr[i]);
        }
        printf("-----\n");
    }
}

// --- CORRECTED Palindrome Check Function ---
void check_palindrome() {
    char input_str[MAX_SIZE];
    char temp_char_stack[MAX_SIZE]; // FIX: Use a local array for characters
    int i, len = 0;
    int temp_top = -1; 
    
    printf("Enter a string to check for palindrome: ");
    // Note the space to consume the newline character
    if (scanf(" %[^\n]", input_str) != 1) return;

    while(input_str[len] != '\0') len++;

    // 1. Push characters onto the local stack
    for (i = 0; i < len; i++) {
        if (temp_top == MAX_SIZE - 1) {
             printf("Error: String is too long for the local stack.\n");
             return;
        }
        temp_char_stack[++temp_top] = input_str[i];
    }
    
    // 2. Pop characters to create the reversed string
    char reversed_str[MAX_SIZE];
    for (i = 0; i < len; i++) {
        reversed_str[i] = temp_char_stack[temp_top--];
    }
    reversed_str[len] = '\0'; 

    // 3. Manual string comparison
    int is_palindrome = 1;
    for (i = 0; i < len; i++) {
        if (input_str[i] != reversed_str[i]) {
            is_palindrome = 0;
            break;
        }
    }
    
    if (is_palindrome) {
        printf("The string '%s' IS a palindrome.\n", input_str);
    } else {
        printf("The string '%s' IS NOT a palindrome.\n", input_str);
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push Element\n2. Pop Element\n3. Check Palindrome\n4. Display Status\n5. Exit\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Clearing buffer.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter integer value to push: ");
                scanf("%d", &value);
                push_element(value);
                break;
            case 2:
                pop_element();
                break;
            case 3:
                check_palindrome();
                break;
            case 4:
                display_status();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please select between 1 and 5.\n");
        }
    }
    return 0;
}
