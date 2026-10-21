#include <assert.h>
#include <stdio.h>

double my_abs(double x) { return x < 0 ? -x : x; }

double solve(long long a, long long *lo, long long *hi);

int main(void) {
    long long lo, hi;
    double k;


    long long a[] = {1, 6, 10, 64, 100, 4957, 2748, 3193};
    double ek[] = {
        1, 2, 2.3650189946, 4.2722976594, 4.9229913962,
        17.3706017009, 14.3238264459, 15.0432163201
    };
    long long el[] = {1, 2, 2, 4, 4, 17, 14, 15};
    long long eh[] = {1, 2, 3, 5, 5, 18, 15, 16};
    for (int i = 0; i < 8; i++) {
        k = solve(a[i], &lo, &hi);
        assert(my_abs(k - ek[i]) < 1e-9);
        assert(lo == el[i] && hi == eh[i]);
    }
    printf("All tests passed!\n");
}
