#include <assert.h>
#include <stdio.h>

int count_trees(int *pos, int k, int a);

int main(void) {
    int pos[] = {2, 5, 5, 9};

    assert(count_trees(pos, 4, 0) == 0);
    assert(count_trees(pos, 4, 1) == 0);
    assert(count_trees(pos, 4, 2) == 1);
    assert(count_trees(pos, 4, 4) == 1);
    assert(count_trees(pos, 4, 5) == 3);
    assert(count_trees(pos, 4, 8) == 3);
    assert(count_trees(pos, 4, 9) == 4);
    assert(count_trees(pos, 4, 2000000000) == 4);

    int one[] = {0};
    assert(count_trees(one, 1, 0) == 1);

    printf("All tests are okay\n");
    return 0;
}