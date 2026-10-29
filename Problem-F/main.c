#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_LEN 100

static char words[MAX_WORDS][MAX_LEN + 1];
static char keys[MAX_WORDS][MAX_LEN + 1];
static int order[MAX_WORDS];
static int group_start[MAX_WORDS];
static int group_size[MAX_WORDS];
static int group_order[MAX_WORDS];

void make_key(const char *word, char *result) {
    int count[26] = {0};
    for (int i = 0; word[i]; i++)
        count[tolower(word[i]) - 'a']++;
    int k = 0;
    for (int c = 0; c < 26; c++)
        for (int i = 0; i < count[c]; i++)
            result[k++] = 'a' + c;
    result[k] = '\0';
}

int are_anagrams(const char *a, const char *b) {
    char key_a[MAX_LEN + 1], key_b[MAX_LEN + 1];
    make_key(a, key_a);
    make_key(b, key_b);
    return strcmp(key_a, key_b) == 0;
}

int compare_groups(int size1, const char *key1, int size2, const char *key2) {
    if (size1 != size2)
        return size2 - size1;
    return strcmp(key1, key2);
}

static int compare_words(const void *a, const void *b) {
    int x = *(const int *) a, y = *(const int *) b;
    int c = strcmp(keys[x], keys[y]);
    return c ? c : x - y;
}

static int compare_group_indices(const void *a, const void *b) {
    int x = *(const int *) a, y = *(const int *) b;
    return compare_groups(group_size[x], keys[order[group_start[x]]],
                          group_size[y], keys[order[group_start[y]]]);
}

int main(void) {
    int z;
    scanf("%d", &z);
    while (z--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%100s", words[i]);
            make_key(words[i], keys[i]);
            order[i] = i;
        }
        qsort(order, n, sizeof(int), compare_words);

        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || !are_anagrams(words[order[i]], words[order[i - 1]])) {
                group_start[groups] = i;
                group_size[groups] = 0;
                groups++;
            }
            group_size[groups - 1]++;
        }
        for (int g = 0; g < groups; g++)
            group_order[g] = g;
        qsort(group_order, groups, sizeof(int), compare_group_indices);

        printf("%d\n", groups);
        for (int g = 0; g < groups; g++) {
            int start = group_start[group_order[g]];
            int size = group_size[group_order[g]];
            printf("%d", size);
            for (int j = 0; j < size; j++)
                printf(" %s", words[order[start + j]]);
            printf("\n");
        }
    }
    return 0;
}
