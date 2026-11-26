#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int power;
    struct node *next;
};

typedef struct node NODE;

NODE *createHeader() {
    NODE *head = (NODE *)malloc(sizeof(NODE));
    head->coeff = 0;
    head->power = -1;
    head->next = head;
    return head;
}

void insertTerm(NODE *head, int coeff, int power) {
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->coeff = coeff;
    newnode->power = power;

    temp = head;
    while (temp->next != head && temp->next->power > power) {
        temp = temp->next;
    }

    
    if (temp->next != head && temp->next->power == power) {
        temp->next->coeff += coeff;
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void readPoly(NODE *head) {
    int degree, coeff, i;
    printf("Enter the degree of polynomial: ");
    scanf("%d", &degree);

    printf("Enter coefficient for each power:\n");
    for (i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &coeff); 
        if (coeff != 0) {
            insertTerm(head, coeff, i);
        }
    }
}

void displayPoly(NODE *head) {
    NODE *temp = head->next;
    int first = 1;

    if (temp == head) {
        printf("0");
        return;
    }

    while (temp != head) {
        
        if (temp->coeff < 0) {
            printf("-");
        } else if (!first && temp->coeff > 0) {
            printf("+");
        }

        
        if (abs(temp->coeff) != 1 || temp->power == 0) {
            printf("%d", abs(temp->coeff));
        }

       
        if (temp->power > 0) {
            printf("x");
            if (temp->power > 1) {
                printf("^%d", temp->power);
            }
        }

       
        first = 0;
        temp = temp->next;
    }
}

NODE *addPoly(NODE *poly1, NODE *poly2) {
    NODE *p, *q, *polysum;
    int sum;

    polysum = createHeader();
    p = poly1->next;
    q = poly2->next;

    while (p != poly1 && q != poly2) {
        if (p->power == q->power) {
            sum = p->coeff + q->coeff;
            if (sum != 0) {
                insertTerm(polysum, sum, p->power);
            }
            p = p->next;
            q = q->next;
        } else if (p->power > q->power) {
            insertTerm(polysum, p->coeff, p->power);
            p = p->next;
        } else {
            insertTerm(polysum, q->coeff, q->power);
            q = q->next;
        }
    }

    while (p != poly1) {
        insertTerm(polysum, p->coeff, p->power);
        p = p->next;
    }

    while (q != poly2) {
        insertTerm(polysum, q->coeff, q->power);
        q = q->next;
    }

    return polysum;
}

int main() {
    NODE *poly1, *poly2, *polysum;
    poly1 = createHeader();
    poly2 = createHeader();

    printf("\n--- Enter POLY1 ---\n");
    readPoly(poly1);

    printf("\n--- Enter POLY2 ---\n");
    readPoly(poly2);

    printf("\nPOLY1   = ");
    displayPoly(poly1);

    printf("\nPOLY2   = ");
    displayPoly(poly2);

    polysum = addPoly(poly1, poly2);
    printf("\nPOLYSUM = ");
    displayPoly(polysum);
    printf("\n");

    return 0;
}

