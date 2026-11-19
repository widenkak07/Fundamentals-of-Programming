
#include <stdio.h>
#include <stdlib.h>

int get_value(unsigned char *v, int i)
{
    unsigned char *p = v + 3 * i;

    return *p + ((unsigned int)*(p + 1) << 8)
              + ((unsigned int)*(p + 2) << 16);
}

void set_value(unsigned char *v, int i, int x)
{
    unsigned char *p = v + 3 * i;

    *p = x & 255;
    *(p + 1) = (x >> 8) & 255;
    *(p + 2) = (x >> 16) & 255;
}

int read_int()
{
    int c = getchar_unlocked();

    while (c != EOF && (c < '0' || c > '9'))
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
    char digits[12];
    int count = 0;

    if (x == 0) {
        putchar_unlocked('0');
        return;
    }

    while (x > 0) {
        *(digits + count) = '0' + x % 10;
        count++;
        x /= 10;
    }

    while (count > 0) {
        count--;
        putchar_unlocked(*(digits + count));
    }
}

int find_best(int n, int k, int b, unsigned char *values,
              int *best_start, long long *best_sum)
{
    int left = 0;
    int bad = 0;
    int best_len = 0;
    long long sum = 0;

    *best_start = 0;
    *best_sum = 0;

    for (int right = 0; right < n; right++) {
        int v = get_value(values, right);

        sum += v;

        if (v % k != 0)
            bad++;

        while (bad > b) {
            int old = get_value(values, left);

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
    int z = read_int();

    for (int test = 0; test < z; test++) {
        int n = read_int();
        int k = read_int();
        int b = read_int();
        int d = read_int();

        unsigned char *values = malloc((size_t)n * 3);

        if (values == NULL)
            return 1;

        for (int i = 0; i < n; i++)
            set_value(values, i, read_int());

        int start;
        long long sum;

        int len = find_best(n, k, b, values, &start, &sum);

        if (len == 0) {
            printf("NO\n");
        } else {
            printf("%d %.*f\n", len, d, (double)sum / len);

            for (int i = 0; i < len; i++) {
                if (i > 0)
                    putchar_unlocked(' ');

                print_int(get_value(values, start + i));
            }

            putchar_unlocked('\n');
        }

        free(values);
    }

    return 0;
}
