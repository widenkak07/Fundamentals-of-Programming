#include <assert.h>
#include <stdio.h>

int count_trees(int *pos, int k, int a);
int count_range(int *pos, int k, int a, int b);

int main(void) {
    int pos[] = {2, 5, 5, 9};


    assert(count_trees(pos, 4, 5) == 3);

    assert(count_range(pos, 4, 0, 1) == 0);
    assert(count_range(pos, 4, 0, 2) == 1);
    assert(count_range(pos, 4, 2, 2) == 1);
    assert(count_range(pos, 4, 3, 4) == 0);
    assert(count_range(pos, 4, 5, 5) == 2);
    assert(count_range(pos, 4, 4, 5) == 2);
    assert(count_range(pos, 4, 5, 9) == 3);
    assert(count_range(pos, 4, 6, 8) == 0);
    assert(count_range(pos, 4, 9, 2000000000) == 1);
    assert(count_range(pos, 4, 0, 2000000000) == 4);
    assert(count_range(pos, 4, 10, 20) == 0);

    int one[] = {0};
    assert(count_range(one, 1, 0, 0) == 1);

    printf("All tests are okay\n");
    return 0;
}