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
            int a;
            scanf("%d", &a);
            printf("%d\n", count_trees(trees, k, a));
        }
    }
    return 0;
}