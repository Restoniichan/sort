#include "srt_insert.h"
#include "srt_tools.h"

void srt_insert(char **a, int n)
{
    int i, j;
    for(i = 1; i < n; ++i)
        for(j = i; j > 0 && cmp(a[j-1], a[j]); --j)
            swp(&a[j], &a[j-1]);
}
