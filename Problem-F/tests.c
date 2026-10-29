#include <assert.h>
#include <stdio.h>
#include <string.h>

void make_key(const char *word, char *result);
int are_anagrams(const char *a, const char *b);
int compare_groups(int size1, const char *key1, int size2, const char *key2);

int main() {
    char key[101];
    make_key("CARE", key);
    assert(strcmp(key, "acer") == 0);
    make_key("eaT", key);
    assert(strcmp(key, "aet") == 0);
    make_key("a", key);
    assert(strcmp(key, "a") == 0);
    make_key("aab", key);
    assert(strcmp(key, "aab") == 0);
    make_key("rear", key);
    assert(strcmp(key, "aerr") == 0);

    assert(are_anagrams("listen", "silent"));
    assert(are_anagrams("CARE", "Acre"));
    assert(are_anagrams("a", "A"));
    assert(!are_anagrams("aab", "ab"));
    assert(!are_anagrams("abc", "abd"));
    assert(!are_anagrams("rear", "race"));

    assert(compare_groups(3, "acer", 1, "aerr") < 0);
    assert(compare_groups(1, "aerr", 3, "acer") > 0);
    assert(compare_groups(1, "aerr", 1, "at") < 0);
    assert(compare_groups(1, "at", 1, "aerr") > 0);
    assert(compare_groups(1, "aab", 1, "ab") < 0);
    assert(compare_groups(2, "efir", 2, "efir") == 0);
    printf("All tests passed!\n");
    return 0;
}