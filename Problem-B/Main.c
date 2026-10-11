#include "stdio.h"
#define N 10000000
int spf[N];
int count[N+1];
int tests();
void sito() {
    for (int i = 2; i <= N; i++) {
        if (spf[i - 1] == 0) {
            for (int j = i; j <= N; j += i) {
                if (spf[j - 1] == 0) {
                    spf[j - 1] = i;
                }
            }
        }
    }
    spf[0] = 1;
    for (int i = 2; i <= N; i++) {
        count[i] = count[i - 1];
        if (spf[i-1] == i) {
            count[i]++;
        }
    }
}
int get_spf(int a) {
    return spf[a-1];
}
int count_primes(int a, int b) {
    return count[b] - count[a - 1];
}
int main() {
    sito();

    int z, a, b;
    get_spf(a);
    count_primes(a, b);

    return tests();
}
