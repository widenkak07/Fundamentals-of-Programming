#include <assert.h>
#include <string.h>
 
#define main solution_main
#include "main.c"
#undef main
 
static void check(int p, int q, const char *in, const char *expected)
{
    char out[128];
    convert(p, q, in, out);
    assert(strcmp(out, expected) == 0);
}
 
int main()
{
    check(10, 2, "7", "111");
    check(2, 10, "1010", "10");
    check(2, 8, "101011", "53");
    check(3, 9, "12012", "165");
    check(5, 8, "12340", "1712");
    check(2, 16, "101001", "29");
    check(16, 2, "BC", "10111100");
    check(10, 2, "0", "0");
    check(2, 2, "0", "0");
    check(10, 16, "255", "FF");
    check(16, 10, "FF", "255");
    check(10, 10, "1000000000000000000", "1000000000000000000");
    check(2, 10, "000000000000000000000000000000000000000000000000000000001010", "10");
    check(10, 2, "1000000000000000000", "110111100000101101101011001110100111011001000000000000000000");
    printf("All tests passed!\n");
    return 0;
}