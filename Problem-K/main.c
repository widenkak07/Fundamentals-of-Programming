#include <stdio.h>
#include <stdlib.h>

int find_best(int n, int k, int b, int *values, int *best_start, long long *best_sum)
{
    int left = 0;
    int bad = 0;
    long long sum = 0;
    int best_len = 0;
    *best_start = 0;
    *best_sum = 0;

    for (int right = 0; right < n; right++) {
        int v = *(values + right);
        sum += v;
        if (v % k != 0)
            bad++;
        while (bad > b) {
            int old = *(values + left);
            sum -= old;
            if (old % k != 0)
                bad--;
            left++;
        }
        int len = right - left + 1;
        if (len > 0 && (len > best_len || (len == best_len && sum >= *best_sum))) {
            best_len = len;
            *best_start = left;
            *best_sum = sum;
        }
    }
    return best_len;
}

long long rounded_average(long long sum, int len, int d)
{
    __int128 power = 1;
    for (int i = 0; i < d; i++)
        power = power * 10;
    return (long long)((2 * sum * power + len) / (2 * (__int128)len));
}

int read_number()
{
    int c = getchar();
    while (c != EOF && (c < '0' || c > '9'))
        c = getchar();
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

int main()
{
    int *values = malloc(4 * 1000000);
    int z = read_number();

    for (int test = 0; test < z; test++) {
        int n = read_number();
        int k = read_number();
        int b = read_number();
        int d = read_number();
        for (int i = 0; i < n; i++)
            *(values + i) = read_number();

        int start;
        long long sum;
        int len = find_best(n, k, b, values, &start, &sum);
        if (len == 0) {
            printf("NO\n");
            continue;
        }

        long long power = 1;
        for (int i = 0; i < d; i++)
            power = power * 10;
        long long average = rounded_average(sum, len, d);
        printf("%d\n", len);
        printf("%lld.%0*lld\n", average / power, d, average % power);
        for (int i = 0; i < len; i++) {
            printf("%d", *(values + start + i));
            putchar(i + 1 < len ? ' ' : '\n');
        }
    }
    return 0;
}
