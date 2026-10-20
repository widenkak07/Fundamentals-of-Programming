#include <assert.h>
#include <stdio.h>

int t_a[] = {3, 1, 4, 2};
int exp_a[] = {1, 2, 3, 4};
int t_b[] = {5, 4, 3, 2, 1, 0};
int exp_b[] = {0, 1, 2, 3, 4, 5};
void insertionSort(int a[], int n);
int(hasTreeSumZero(int a[], int n));
void test_insertionSort(void) {
    insertionSort(t_a, 4);
    insertionSort(t_b, 6);
    for (int i = 0; i < 4; i++) {
        assert(t_a[i] == exp_a[i]);


    }
    for (int i = 0; i < 6; i++) {
        assert(t_b[i] == exp_b[i]);
    }

}
void test_hasTreeSumZero(){
    assert(hasTreeSumZero(exp_a, 4) == 0);
    assert(hasTreeSumZero(exp_b, 6) == 1);
}
int main() {
    test_insertionSort();
    test_hasTreeSumZero();
    printf("All tests passed!\n");
    return 0;
}