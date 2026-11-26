#include <stdio.h>
#include <stdlib.h>

// Defining the maximum size of the stack (MAX > 15)
#define MAX 20

// Global variables for stack implementation
int stack[MAX];
int top = -1;

// Function prototypes
void push(int element);
int pop();
void display();
void checkOverflowUnderflow();

int main() {
    int choice, value;

    
        printf("\n--- STACK OPERATIONS MENU ---\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Demonstrate Overflow and Underflow Status\n");
        printf("4. Display Stack Status\n");
        printf("5. Exit\n");
        while (1) {
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the integer element to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Successfully popped %d from the stack.\n", value);
                }
                break;
            case 3:
                checkOverflowUnderflow();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    }
    return 0;
}

// a. Function to Push an Element on to Stack
void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d onto a full stack.\n", element);
    } else {
        top++;
        stack[top] = element;
        printf("%d successfully pushed onto the stack.\n", element);
    }
}

// b. Function to Pop an Element from Stack
int pop() {
    if (top == -1) {
        printf(" Stack Underflow! Cannot pop from an empty stack.\n", top);
        return -1; // Return error flag
    } else {
        int poppedElement = stack[top];
        top--;
        return poppedElement;
    }
}

// c. Function to Demonstrate Overflow and Underflow situations
void checkOverflowUnderflow() {
    printf("\n--- Stack Capacity Verification ---\n");
    printf("Current Top Index: %d\n", top);
    printf("Maximum Capacity: %d\n", MAX);
    
    if (top == -1) {
        printf("UNDERFLOW condition met. \n");
        
    } else if (top == MAX - 1) {
        printf("OVERFLOW condition met. \n");
    } else {
        printf("Normal operational state. Stack has %d elements.\n", top + 1);
    }
}

// d. Function to Display the status of Stack at any given point of time
void display() {
    if (top == -1) {
        printf("Stack Status: Stack is EMPTY.\n");
        return;
    }
    
    printf("Stack Status: Active (%d/%d elements occupied)\n", top + 1, MAX);
    printf("Elements (from Top to Bottom):\n");
    for (int i = top; i >= 0; i--) {
        if (i == top) {
            printf(" [%d] <-- TOP\n", stack[i]);
        } else {
            printf(" [%d]\n", stack[i]);
        }
    }
}

