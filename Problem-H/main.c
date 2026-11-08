#include <stdio.h>
#include <string.h>

#define MAX 1500

unsigned short A[MAX][MAX];
unsigned short B[MAX][MAX];
unsigned short C[MAX][MAX];

void read_matrix(unsigned short matrix[][MAX], int rows, int columns)
{
    int i, j, value;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &value);
            matrix[i][j] = value % 1000;
        }
    }
}

void print_matrix(unsigned short matrix[][MAX], int rows, int columns)
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%03d", matrix[i][j]);
        }
        printf("\n");
    }
}

void copy_matrix(unsigned short from[][MAX], unsigned short to[][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            to[i][j] = from[i][j];
        }
    }
}

void set_identity(unsigned short matrix[][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = (i == j);
        }
    }
}

void multiply(unsigned short x[][MAX], unsigned short y[][MAX], unsigned short out[][MAX], int n, int m, int k)
{
    int row[MAX];
    int i, j, l;
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            row[j] = 0;
        }
        for (l = 0; l < m; l++) {
            int factor = x[i][l];
            for (j = 0; j < k; j++) {
                row[j] += factor * y[l][j];
            }
        }
        for (j = 0; j < k; j++) {
            out[i][j] = row[j] % 1000;
        }
    }
}

void power(int n, int p)
{
    set_identity(B, n);
    while (p > 0) {
        if (p % 2 == 1) {
            multiply(B, A, C, n, n, n);
            copy_matrix(C, B, n);
        }
        p = p / 2;
        if (p > 0) {
            multiply(A, A, C, n, n, n);
            copy_matrix(C, A, n);
        }
    }
}

int main()
{
    int z, p, n1, m1, n2, m2;
    char operation[16];
    scanf("%d", &z);
    while (z--) {
        scanf("%s", operation);
        if (strcmp(operation, "POWER") == 0) {
            scanf("%d", &p);
            scanf("%d %d", &n1, &m1);
            read_matrix(A, n1, m1);
            if (n1 != m1) {
                printf("ERROR POWER\n");
            } else {
                power(n1, p);
                print_matrix(B, n1, n1);
            }
        } else {
            scanf("%d %d", &n1, &m1);
            read_matrix(A, n1, m1);
            scanf("%d %d", &n2, &m2);
            read_matrix(B, n2, m2);
            if (m1 != n2) {
                printf("ERROR MULTIPLY\n");
            } else {
                multiply(A, B, C, n1, m1, m2);
                print_matrix(C, n1, m2);
            }
        }
    }
    return 0;
}
