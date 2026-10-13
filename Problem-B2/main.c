#include <stdio.h>

#define N 8000000

int spf[N + 1];

int main() {
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= N; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }
    }

    int z;
    scanf("%d", &z);
    while (z--) {
        int n;
        scanf("%d", &n);

        long long sum = 1;
        while (n > 1) {
            int p = spf[n];
            long long term = 1, pw = 1;
            while (n % p == 0) {
                n /= p;
                pw *= p;
                term += pw;
            }
            sum *= term;
        }
        printf("%lld\n", sum);
    }
    return 0;
}