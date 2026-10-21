#include <stdio.h>

long long V(long long k) { return k * k * k - k * k + k; }


double solve(long long a, long long *lo, long long *hi) {
    long long l = 1, r = 300;
    while (l < r) {
        long long m = (l + r + 1) / 2;
        if (V(m) <= a) l = m; else r = m - 1;
    }
    *lo = l;
    if (V(l) == a) {
        *hi = l;
        return l;
    }
    *hi = l + 1;

    double x = l + 1;
    for (int i = 0; i < 20; i++)
        x = x - (x * x * x - x * x + x - a) / (3 * x * x - 2 * x + 1);
    return x;
}

int main(void) {
    int z;
    long long a, lo, hi;
    scanf("%d", &z);
    while (z--) {
        scanf("%lld", &a);
        double k = solve(a, &lo, &hi);
        printf("%.10f %lld %lld\n", k, lo, hi);
    }
    return 0;
}