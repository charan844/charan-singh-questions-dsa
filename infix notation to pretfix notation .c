#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    int top;
    char items[MAX];
} Stack;

// Stack operations
void initStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

// Function to check operator precedence
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Function to reverse a string
void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int j = 0;

    for (int i = 0; infix[i]; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token; // Add operands to output
        } else if (token == '(') {
            push(&s, token); // Push '(' to stack
        } else if (token == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Pop '(' from stack
        } else { // Operator
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(token)) {
                postfix[j++] = pop(&s);
            }
            push(&s, token);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; // Null terminate the postfix string
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    // Step 1: Reverse the infix expression
    reverse(infix);
    
    // Step 2: Change '(' to ')' and vice versa
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Step 3: Convert modified infix to postfix
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    
    // Step 4: Reverse the postfix expression to get prefix
    reverse(postfix);
    strcpy(prefix, postfix);
}

// Main function to test the conversion
int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0; // Remove trailing newline

    infixToPrefix(infix, prefix);
    
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
Explanation
