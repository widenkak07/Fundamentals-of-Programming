#include <assert.h>
#include <stdio.h>

int advance(const int *a, int m, int pos, int x)
{
    while (pos < m)
    {
        if (*(a + pos) == x)
            return pos + 1;
        pos++;
    }
    return -1;
}

int main()
{
    int a[4] = {1, 5, 4, 5};
    assert(advance(a, 4, 0, 1) == 1);
    assert(advance(a, 4, 0, 5) == 2);
    assert(advance(a, 4, 2, 5) == 4);
    assert(advance(a, 4, 0, 2) == -1);
    assert(advance(a, 4, 4, 1) == -1);
    printf("All tests passed!\n");
    return 0;
}