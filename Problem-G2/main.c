#include <stdio.h>
#include <string.h>

int fits_in_register(int r, long long x)
{
    if (r == 64) {
        return 1;
    }
    long long limit = 1LL << (r - 1);
    return x >= -limit && x < limit;
}

void write_register(int r, long long x, char *out)
{
    if (!fits_in_register(r, x)) {
        strcpy(out, "ERROR");
        return;
    }

    unsigned long long bits = (unsigned long long)x;
    int i;
    for (i = 0; i < r; i++) {
        int bit = (bits >> (r - 1 - i)) & 1;
        out[i] = '0' + bit;
    }
    out[r] = '\0';
}

void read_register(const char *in, char *out)
{
    int r = strlen(in);

    unsigned long long bits = 0;
    int i;
    for (i = 0; i < r; i++) {
        bits = bits * 2 + (in[i] - '0');
    }

    if (in[0] == '0') {
        sprintf(out, "%llu", bits);
        return;
    }

    unsigned long long magnitude = ~bits + 1;
    if (r < 64) {
        magnitude = magnitude & ((1ULL << r) - 1);
    }
    sprintf(out, "-%llu", magnitude);
}

int main()
{
    int z, r;
    long long x;
    char command[16], number[128], result[128];
    scanf("%d", &z);
    while (z--) {
        scanf("%s", command);
        if (strcmp(command, "WRITE") == 0) {
            scanf("%d %lld", &r, &x);
            write_register(r, x, result);
        } else {
            scanf("%s", number);
            read_register(number, result);
        }
        puts(result);
    }
    return 0;
}

