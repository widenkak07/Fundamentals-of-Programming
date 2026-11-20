#include <stdio.h>
#include <stdlib.h>

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
    int z;
    scanf("%d", &z);
    while (z--)
    {
        int m;
        scanf("%d", &m);
        int *a = malloc(m * sizeof(int));
        for (int i = 0; i < m; i++)
            scanf("%d", a + i);
        int n;
        scanf("%d", &n);
        while (n--)
        {
            int k;
            scanf("%d", &k);
            int pos = 0;
            int ok = 1;
            for (int j = 0; j < k; j++)
            {
                int x;
                scanf("%d", &x);
                if (ok)
                {
                    pos = advance(a, m, pos, x);
                    if (pos < 0)
                        ok = 0;
                }
            }
            puts(ok ? "YES" : "NO");
        }
        free(a);
    }
    return 0;
}