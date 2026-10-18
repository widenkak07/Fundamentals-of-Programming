#include <stdio.h>

int trees[1000000];

int count_trees(int *pos, int k, int a) {
    int lo = 0, hi = k;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (pos[mid] <= a)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

int count_range(int *pos, int k, int a, int b) {
    return count_trees(pos, k, b) - count_trees(pos, k, a - 1);
}

int main(void) {
    int z;
    scanf("%d", &z);
    while (z--) {
        int k, q;
        scanf("%d", &k);
        int sum = 0;
        for (int i = 0; i < k; i++) {
            int d;
            scanf("%d", &d);
            sum += d;
            trees[i] = sum;
        }
        scanf("%d", &q);
        while (q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", count_range(trees, k, a, b));
        }
    }
    return 0;
}