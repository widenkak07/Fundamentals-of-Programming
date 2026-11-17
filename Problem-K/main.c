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

double average(long long sum, int len)
{
    return (double)sum / len;
}

int main()
{
    int *values = malloc(4 * 1000000);

    int z;
    scanf("%d", &z);
    for (int test = 0; test < z; test++) {
        int n, k, b, d;
        scanf("%d %d %d %d", &n, &k, &b, &d);
        for (int i = 0; i < n; i++)
            scanf("%d", values + i);

        int start;
        long long sum;
        int len = find_best(n, k, b, values, &start, &sum);
        if (len == 0) {
            printf("NO\n");
            continue;
        }

        printf("%d\n", len);
        printf("%.*f\n", d, average(sum, len));
        for (int i = 0; i < len; i++) {
            printf("%d", *(values + start + i));
            putchar(i + 1 < len ? ' ' : '\n');
        }
    }
    return 0;
}