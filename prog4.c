#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void addJob() {
    int job;
    if (rear == MAX - 1) {
        printf("\nPrinter queue overflow.\n");
        return;
    }
    printf("Enter print job ID: ");
    scanf("%d", &job);
    
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = job;
    printf("Print job %d added successfully.\n", job);
}

void processJob() {
    int job;
    if (front == -1 || front > rear) {
        printf("\nPrinter queue underflow!\n");
        return;
    }
    job = queue[front];
    printf("\nProcessing print job: %d\n", job);
    front++;
    
    if (front > rear) {
        front = rear = -1; 
    }
}

void displayCount() {
    if (front == -1) {
        printf("\nNo print jobs waiting in the queue.\n");
    } else {
        printf("\nNumber of print jobs waiting: %d\n", rear - front + 1);
    }
}

int main() {
    int choice;
    
        printf("\n--- PRINTER QUEUE SIMULATION ---\n");
        printf("1. Add a print job\n");
        printf("2. Process a print job\n");
        printf("3. Display number of waiting jobs\n");
        printf("4. Demonstrate overflow and underflow\n");
        printf("5. Exit\n");
        while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addJob();
                break;
            case 2:
                processJob();
                break;
            case 3:
                displayCount();
                break;
            case 4:
                printf("\nOverflow occurs when the queue is full (MAX = %d).\n", MAX);
                printf("Underflow occurs when the queue is empty.\n");
                break;
            case 5:
                printf("\nExiting printer queue simulation.\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0; 
}

