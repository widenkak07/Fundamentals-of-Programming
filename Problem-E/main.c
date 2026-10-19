#include <stdio.h>
int a[100000];
int n, z,l,m,i;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        char swapped = 0;
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
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
        bubbleSort(a, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        if (hasTreeSumZero(a, n) == 0) {
            printf("NO\n");
        }else {
            printf("YES %d %d %d ", i, l, m);
        }

    }
    return 0;
}
