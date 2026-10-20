#include <stdio.h>
int a[100000];
int n, z,l,m,i;

void insertionSort(int a[], int n) {
    for (int i=1;i<n;i++) {
        int key = a[i];
        int j = i-1;
        while (j>=0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
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
        insertionSort(a, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        if (hasTreeSumZero(a, n) == 0) {
            printf("NO\n");
        }else {
            printf("YES %d %d %d \n", i, l, m);
        }

    }
    return 0;
}
