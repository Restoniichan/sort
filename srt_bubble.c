#include "srt_bubble.h"
#include "srt_tools.h"

void srt_bubble(char **a, int n) {
    int i, j;
    for(i = n; i > 0; --i)
        for(j = n-1; j > n-i; --j)
            if(cmp(a[j-1], a[j]))
                swp(&a[j-1], &a[j]);
}
