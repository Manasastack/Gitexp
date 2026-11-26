#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int val;
} Element;

int main() {
    Element A[MAX], B[MAX], Sum[MAX], TransposeSum[MAX];
    int rows1, cols1, rows2, cols2;
    int i, j, k, temp_val;

    printf("=== Sparse Matrix Operations ===\n\n");

    // --- Input Matrix A ---
    printf("Enter number of rows and columns for Matrix A (e.g., 3 4): ");
    scanf("%d %d", &rows1, &cols1);

    k = 1;
    printf("Enter the elements of Matrix A row by row:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &temp_val);
            if (temp_val != 0) {
                A[k].row = i;
                A[k].col = j;
                A[k].val = temp_val;
                k++;
            }
        }
    }
    A[0].row = rows1;
    A[0].col = cols1;
    A[0].val = k - 1;

    // --- Input Matrix B ---
    printf("\nEnter number of rows and columns for Matrix B (e.g., 3 4): ");
    scanf("%d %d", &rows2, &cols2);

    if (rows1 != rows2 || cols1 != cols2) {
        printf("\n[Error] Matrix addition requires both matrices to have identical dimensions!\n");
        return 1;
    }

    k = 1;
    printf("Enter the elements of Matrix B row by row:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &temp_val);
            if (temp_val != 0) {
                B[k].row = i;
                B[k].col = j;
                B[k].val = temp_val;
                k++;
            }
        }
    }
    B[0].row = rows2;
    B[0].col = cols2;
    B[0].val = k - 1;

    // --- Print Matrix A ---
    printf("\n--- Matrix A ---\nRow\tCol\tValue\n");
    for (i = 0; i <= A[0].val; i++) {
        printf("%d\t%d\t%d\n", A[i].row, A[i].col, A[i].val);
    }

    // --- Print Matrix B ---
    printf("\n--- Matrix B ---\nRow\tCol\tValue\n");
    for (i = 0; i <= B[0].val; i++) {
        printf("%d\t%d\t%d\n", B[i].row, B[i].col, B[i].val);
    }

    // --- Matrix Addition (A + B) ---
    Sum[0].row = A[0].row;
    Sum[0].col = A[0].col;
    int pA = 1, pB = 1, pS = 1;

    while (pA <= A[0].val && pB <= B[0].val) {
        if (A[pA].row == B[pB].row) {
            if (A[pA].col == B[pB].col) {
                int total = A[pA].val + B[pB].val;
                if (total != 0) {
                    Sum[pS].row = A[pA].row;
                    Sum[pS].col = A[pA].col;
                    Sum[pS].val = total;
                    pS++;
                }
                pA++;
                pB++;
            } else if (A[pA].col < B[pB].col) {
                Sum[pS++] = A[pA++];
            } else {
                Sum[pS++] = B[pB++];
            }
        } else if (A[pA].row < B[pB].row) {
            Sum[pS++] = A[pA++];
        } else {
            Sum[pS++] = B[pB++];
        }
    }

    while (pA <= A[0].val) Sum[pS++] = A[pA++];
    while (pB <= B[0].val) Sum[pS++] = B[pB++];
    Sum[0].val = pS - 1;

    // --- Print Sum Matrix ---
    printf("\n--- Sum (A + B) ---\nRow\tCol\tValue\n");
    for (i = 0; i <= Sum[0].val; i++) {
        printf("%d\t%d\t%d\n", Sum[i].row, Sum[i].col, Sum[i].val);
    }

    // --- Fast Transpose of Sum Matrix ---
    TransposeSum[0].row = Sum[0].col;
    TransposeSum[0].col = Sum[0].row;
    TransposeSum[0].val = Sum[0].val;

    int count[MAX] = {0};
    int start_pos[MAX] = {0};

    // Count frequency of elements in each column of the Sum matrix
    for (i = 1; i <= Sum[0].val; i++) {
        count[Sum[i].col]++;
    }

    // Determine starting position for each column row in TransposeSum
    start_pos[0] = 1;
    for (i = 1; i < Sum[0].col; i++) {
        start_pos[i] = start_pos[i - 1] + count[i - 1];
    }

    // Map the elements to their transposed layout
    for (i = 1; i <= Sum[0].val; i++) {
        int pos = start_pos[Sum[i].col]++;
        TransposeSum[pos] = Sum[i];
        TransposeSum[pos].row = Sum[i].col;
        TransposeSum[pos].col = Sum[i].row;
    }

    // --- Print Transpose of Sum ---
    printf("\n--- Transpose of Sum ---\nRow\tCol\tValue\n");
    for (i = 0; i <= TransposeSum[0].val; i++) {
        printf("%d\t%d\t%d\n", TransposeSum[i].row, TransposeSum[i].col, TransposeSum[i].val);
    }

    return 0;
}

