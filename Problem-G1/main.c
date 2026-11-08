#include <stdio.h>

int char_to_digit(char c)
{
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}

char digit_to_char(int digit)
{
    if (digit < 10) {
        return '0' + digit;
    }
    return 'A' + digit - 10;
}

void convert(int p, int q, const char *in, char *out)
{
    unsigned long long value = 0;
    int i;
    for (i = 0; in[i] != '\0'; i++) {
        value = value * p + char_to_digit(in[i]);
    }

    char buffer[128];
    int length = 0;
    do {
        buffer[length] = digit_to_char(value % q);
        length++;
        value = value / q;
    } while (value > 0);

    for (i = 0; i < length; i++) {
        out[i] = buffer[length - 1 - i];
    }
    out[length] = '\0';
}

int main()
{
    int z, p, q;
    char command[16], number[128], result[128];
    scanf("%d", &z);
    while (z--) {
        scanf("%s %d %d %s", command, &p, &q, number);
        convert(p, q, number, result);
        puts(result);
    }
    return 0;
}