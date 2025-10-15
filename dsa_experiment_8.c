#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 10

// Simple char stack implementation
char stack[MAX_SIZE];
int top = -1;

void push(char item) {
if (top == MAX_SIZE - 1) {
printf("Stack Overflow!\n");
return;
}
stack[++top] = item;
}

char pop() {
if (top == -1) {
return '\0'; // Return null char on underflow
}
return stack[top--];
}

char peek() {
if (top == -1) {
return '\0';
}
return stack[top];
}

// Function to return precedence value
int precedence(char op) {
if (op == '^') return 3;
if (op == '*' || op == '/' || op == '%') return 2;
if (op == '+' || op == '-') return 1;
return 0; // For operands and parentheses
}

void infixToPostfix(char infix[], char postfix[]) {
int i = 0, j = 0;
char next_char;

while (infix[i] != '\0') {
next_char = infix[i];

if (isalnum(next_char)) {
// Operands go directly to output
postfix[j++] = next_char;
} else if (next_char == '(') {
// Push opening parenthesis onto stack
push(next_char);
} else if (next_char == ')') {
// Pop operators until opening parenthesis is found
while (peek() != '(' && peek() != '\0') {
postfix[j++] = pop();
}
if (peek() == '(') {
pop(); // Discard the '('
} else {
printf("\nError: Mismatched parentheses.\n");
return;
}
} else {
// Operator logic: Pop higher/equal precedence operators from stack
while (precedence(peek()) >= precedence(next_char)) {
postfix[j++] = pop();
}
push(next_char);
}
i++;
}

// Pop remaining operators from stack
while (peek() != '\0') {
if (peek() == '(') {
printf("\nError: Mismatched parentheses.\n");
return;
}
postfix[j++] = pop();
}
postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
char infix[MAX_SIZE], postfix[MAX_SIZE];

printf("Enter an Infix Expression: ");
scanf("%s", infix); // Reading without spaces for simplicity

infixToPostfix(infix, postfix);

if (postfix[0] != '\0') {
printf("Postfix Expression: %s\n", postfix);
}

return 0;
}
