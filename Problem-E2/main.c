#include <stdio.h>
int a[100000];
int n, z, l, m,x;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minInx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minInx]) {
                minInx = j;
            }
        }
        if (minInx != i) {
            int swap = a[i];
            a[i] = a[minInx];
            a[minInx] = swap;
        }
    }
}

int hasTreeSumZero(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) break;
        if (i > 0 && a[i] == a[i-1]) continue;
        l = i; m = n - 1;
        while (l <= m) {
            long long sum = (long long)a[i] + a[l] + a[m];
            if (sum == 0) { x = i; return 1; }
            else if (sum > 0) m--;
            else l++;
        }
    }
    return 0;
}
int main() {
    scanf("%d", &z);
    while (z--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        selectionSort(a, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        if (hasTreeSumZero(a, n) == 0) {
            printf("NO\n");
        } else {
            printf("YES %d %d %d\n", x, l, m);
        }
    }
    return 0;
}
