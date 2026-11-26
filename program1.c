#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int Book_ID;
    char Title[50];
    char Author[50];
    float Price;
    char Status[15];
};

struct Book* b = NULL;
int n = 0;


void create() {
    int i;
    printf("Enter number of books: \n");
    scanf("%d", &n);
    
  
    if (b != NULL) {
        free(b);
    }
    
    b = (struct Book*) malloc(n * sizeof(struct Book));
    
    for(i = 0; i < n; i++) {
        printf("\nEnter details of book %d\n", i + 1);
        printf("Book ID: ");
        scanf("%d", &b[i].Book_ID);
        
        printf("Title: ");
        scanf(" %[^\n]", b[i].Title); 
        
        printf("Author: ");
        scanf(" %[^\n]", b[i].Author); 
        
        printf("Price: ");
        scanf("%f", &b[i].Price);
        
        strcpy(b[i].Status, "Available");
    }
    printf("\nBook records added successfully.\n");
}


void display() {
    int i;
    if(n == 0) {
        printf("\nNo records found.\n");
        return;
    }
    printf("\n--- BOOK DETAILS --- \n");
    for(i = 0; i < n; i++) {
        printf("\nBook_ID : %d", b[i].Book_ID);
        printf("\nTitle   : %s", b[i].Title);
        printf("\nAuthor  : %s", b[i].Author);
        printf("\nPrice   : %.2f", b[i].Price);
        printf("\nStatus  : %s\n", b[i].Status);
    }
}

// FUNCTION TO SEARCH A BOOK
void search() {
    int id, i, found = 0;
    printf("Enter book ID to search: ");
    scanf("%d", &id);
    for(i = 0; i < n; i++) {
        if(b[i].Book_ID == id) {
            printf("\nBook_ID : %d", b[i].Book_ID);
            printf("\nTitle   : %s", b[i].Title);
            printf("\nAuthor  : %s", b[i].Author);
            printf("\nPrice   : %.2f", b[i].Price);
            printf("\nStatus  : %s\n", b[i].Status);
            found = 1;
            break;
        }
    }
    if(found == 0) printf("Book not found.\n");
}

// FUNCTION TO ISSUE A BOOK
void issuebook() {
    int id, i;
    printf("Enter book ID to issue: ");
    scanf("%d", &id);
    for(i = 0; i < n; i++) {
        if(b[i].Book_ID == id) {
            if(strcmp(b[i].Status, "Available") == 0) {
                strcpy(b[i].Status, "Issued");
                printf("Book issued successfully.\n");
            } else {
                printf("Book is already issued.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

// FUNCTION TO RETURN A BOOK
void returnBook() {
    int id, i;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    for(i = 0; i < n; i++) {
        if(b[i].Book_ID == id) {
            if(strcmp(b[i].Status, "Issued") == 0) {
                strcpy(b[i].Status, "Available");
                printf("Book returned successfully.\n");
            } else {
                printf("Book is already available.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

// MAIN FUNCTION
int main() {
    int choice;
    while(1) {
        printf("\n--- LIBRARY MENU ---");
        printf("\n1. Add Book records");
        printf("\n2. Display Book records");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: issuebook(); break;
            case 5: returnBook(); break;
            case 6: 
                free(b); // Fixed: Freeing the actual pointer array
                printf("Program Ended\n");
                return 0;
            default: printf("Invalid choice! \n");
        }
    }
    return 0;
}

