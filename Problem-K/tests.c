#include <assert.h>
#include <stdio.h>

int find_best(int n, int k, int b, int *values, int *best_start, long long *best_sum);
long long rounded_average(long long sum, int len, int d);

int main()
{
    int start;
    long long sum;

    int a[] = {1, 8, 3, 2, 5, 1, 2, 3};
    assert(find_best(8, 2, 1, a, &start, &sum) == 3);
    assert(start == 1);
    assert(sum == 13);

    int b[] = {1, 8, 2, 5, 1, 2};
    assert(find_best(6, 3, 0, b, &start, &sum) == 0);

    int c[] = {2, 4, 6};
    assert(find_best(3, 2, 0, c, &start, &sum) == 3);
    assert(start == 0);
    assert(sum == 12);

    int d[] = {4, 1, 2, 1, 6};
    assert(find_best(5, 2, 0, d, &start, &sum) == 1);
    assert(start == 4);
    assert(sum == 6);

    int e[] = {1, 2, 2, 1};
    assert(find_best(4, 2, 1, e, &start, &sum) == 3);
    assert(start == 1);
    assert(sum == 5);

    int f[] = {7};
    assert(find_best(1, 5, 0, f, &start, &sum) == 0);

    assert(rounded_average(13, 3, 3) == 4333);
    assert(rounded_average(5, 3, 1) == 17);
    assert(rounded_average(12, 3, 2) == 400);
    assert(rounded_average(0, 1, 2) == 0);

    printf("All tests passed!\n");
    return 0;
}
