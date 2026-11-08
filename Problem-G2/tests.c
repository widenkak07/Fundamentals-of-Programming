#include <assert.h>
#include <string.h>

#define main solution_main
#include "main.c"
#undef main

static void check_write(int r, long long x, const char *expected)
{
    char out[128];
    write_register(r, x, out);
    assert(strcmp(out, expected) == 0);
}

static void check_read(const char *in, const char *expected)
{
    char out[128];
    read_register(in, out);
    assert(strcmp(out, expected) == 0);
}

static void check_round_trip(int r, long long x, const char *expected)
{
    char bits[128];
    char back[128];
    write_register(r, x, bits);
    read_register(bits, back);
    assert(strcmp(back, expected) == 0);
}

int main(void)
{
    check_write(8, 12, "00001100");
    check_write(8, -12, "11110100");
    check_write(8, -128, "10000000");
    check_write(8, -130, "ERROR");
    check_write(8, 127, "01111111");
    check_write(8, 128, "ERROR");
    check_write(8, 0, "00000000");
    check_write(4, 7, "0111");
    check_write(4, 8, "ERROR");
    check_write(4, -8, "1000");
    check_write(4, -9, "ERROR");
    check_write(4, -1, "1111");
    check_write(64, -1,
        "11111111" "11111111" "11111111" "11111111"
        "11111111" "11111111" "11111111" "11111111");
    check_write(64, 1000000000000000000LL,
        "0000" "110111100000101101101011001110100111011001000000000000000000");

    check_read("00001100", "12");
    check_read("01111111", "127");
    check_read("11111111", "-1");
    check_read("10000000", "-128");
    check_read("0000", "0");
    check_read("0111", "7");
    check_read("1000", "-8");
    check_read(
        "11111111" "11111111" "11111111" "11111111"
        "11111111" "11111111" "11111111" "11111111", "-1");
    check_read(
        "0000" "110111100000101101101011001110100111011001000000000000000000",
        "1000000000000000000");

    check_round_trip(64, 1000000000000000000LL, "1000000000000000000");
    check_round_trip(64, -1000000000000000000LL, "-1000000000000000000");
    check_round_trip(17, -65536, "-65536");
    check_round_trip(17, 65535, "65535");
    printf("All tests passed!\n");
    return 0;
}