#include <assert.h>
 
#define main solution_main
#include "main.c"
#undef main
 
static void set_matrix(unsigned short matrix[][MAX], int rows, int columns, const int *values)
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            matrix[i][j] = values[i * columns + j];
        }
    }
}
 
static void check_matrix(unsigned short matrix[][MAX], int rows, int columns, const int *expected)
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            assert(matrix[i][j] == expected[i * columns + j]);
        }
    }
}
 
int main()
{
    int a1[] = {1, 2, 3, 4};
    int b1[] = {5, 6, 7, 8};
    int c1[] = {19, 22, 43, 50};
    set_matrix(A, 2, 2, a1);
    set_matrix(B, 2, 2, b1);
    multiply(A, B, C, 2, 2, 2);
    check_matrix(C, 2, 2, c1);

    int a2[] = {1, 2, 3, 4, 5, 6};
    int b2[] = {7, 8, 9, 10, 11, 12};
    int c2[] = {58, 64, 139, 154};
    set_matrix(A, 2, 3, a2);
    set_matrix(B, 3, 2, b2);
    multiply(A, B, C, 2, 3, 2);
    check_matrix(C, 2, 2, c2);

    int a3[] = {999, 999};
    int b3[] = {999, 999};
    int c3[] = {2};
    set_matrix(A, 1, 2, a3);
    set_matrix(B, 2, 1, b3);
    multiply(A, B, C, 1, 2, 1);
    check_matrix(C, 1, 1, c3);

    int fib[] = {1, 1, 1, 0};
    int fib10[] = {89, 55, 55, 34};
    set_matrix(A, 2, 2, fib);
    power(2, 10);
    check_matrix(B, 2, 2, fib10);

    int fib30[] = {269, 40, 40, 229};
    set_matrix(A, 2, 2, fib);
    power(2, 30);
    check_matrix(B, 2, 2, fib30);

    int a4[] = {1, 2, 3, 4};
    set_matrix(A, 2, 2, a4);
    power(2, 1);
    check_matrix(B, 2, 2, a4);

    int a5[] = {2};
    int c5[] = {24};
    set_matrix(A, 1, 1, a5);
    power(1, 10);
    check_matrix(B, 1, 1, c5);

    int a6[] = {2, 0, 0, 3};
    int c6[] = {32, 0, 0, 243};
    set_matrix(A, 2, 2, a6);
    power(2, 5);
    check_matrix(B, 2, 2, c6);

    int a7[] = {1, 2, 0, 0, 1, 3, 4, 0, 1};
    int c7[] = {25, 6, 18, 36, 25, 9, 12, 24, 25};
    set_matrix(A, 3, 3, a7);
    power(3, 3);
    check_matrix(B, 3, 3, c7);
    printf("All tests passed!\n");
    return 0;
}