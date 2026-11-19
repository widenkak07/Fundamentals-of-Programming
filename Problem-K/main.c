
#include <stdio.h>
#include <stdlib.h>

int read_int()
{
    int c = getchar_unlocked();

    while (c != EOF && c <= ' ')
        c = getchar_unlocked();

    int x = 0;

    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar_unlocked();
    }

    return x;
}

void print_int(int x)
{
    if (x >= 10)
        print_int(x / 10);

    putchar_unlocked('0' + x % 10);
}

int find_best(int n, int k, int b, int *values,
              int *best_start, long long *best_sum)
{
    int left = 0;
    int bad = 0;
    int best_len = 0;

    long long sum = 0;
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

        if (len > best_len ||
            (len == best_len && sum >= *best_sum)) {

            best_len = len;
            *best_start = left;
            *best_sum = sum;
        }
    }

    return best_len;
}

int main()
{
    int *values = malloc(sizeof(int) * 1000000);

    if (values == NULL)
        return 1;

    int z = read_int();

    for (int test = 0; test < z; test++) {

        int n = read_int();
        int k = read_int();
        int b = read_int();
        int d = read_int();

        for (int i = 0; i < n; i++)
            *(values + i) = read_int();

        int start;
        long long sum;

        int len = find_best(n, k, b, values, &start, &sum);

        if (len == 0) {
            printf("NO\n");
            continue;
        }

        printf("%d %.*f\n", len, d, (double)sum / len);

        print_int(*(values + start));

        for (int i = 1; i < len; i++) {
            putchar_unlocked(' ');
            print_int(*(values + start + i));
        }

        putchar_unlocked('\n');
    }

    free(values);

    return 0;
}