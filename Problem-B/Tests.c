#include <stdio.h>
#include <assert.h>

int get_spf(int x);
int count_primes(int a, int b);

void run_tests() {
    assert(get_spf(1) == 1);
    assert(get_spf(10) == 2);
    assert(get_spf(19) == 19);
    assert(get_spf(505) == 5);
    assert(count_primes(1, 10) == 4);
    assert(count_primes(2, 19) == 8);
    assert(count_primes(3, 19) == 7);
    assert(count_primes(15, 20) == 2);
}

int tests() {
    run_tests();
    printf("Wszystkie testy się zgadzają.\n");
    return 0;
}