#include <stdio.h>
int a[100000];
int n, z, l, m, i, j;

void selectionSort(int a[], int n) {
    for (i = 0; i < n-1; i++) {
        int minInx = i;
        for (j = i+1; j < n; j++) {
            if (a[j] < a[minInx]) {
                minInx = j;
            }
        }
        int swap = a[i];
        a[i] = a[minInx];
        a[minInx] = swap;
    }
}

int hasTreeSumZero(int a[], int n) {
    for (i = 0; i < n - 1; i++) {
        l = i, m = n - 1;
        while (l <= m) {
            int sum = a[i] + a[l] + a[m];
            if (sum == 0) {
                return 1;
            } else if (sum > 0) {
                m--;
            } else if (sum < 0) {
                l++;
            }
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
            printf("YES %d %d %d ", i, l, m);
        }
    }
    return 0;
}
