#include "srt_quick.h"
#include "srt_tools.h"

int part(char **a, int lo, int hi) {
    char *pivot = a[(lo+hi)/2];
    int i = lo-1, j = hi+1;

    while(i < j) {
        do
            ++i;
        while(cmp(pivot, a[i]));

        do
            --j;
        while(cmp(a[j], pivot));

        if(i < j)
            swp(&a[i], &a[j]);
    }
    return j;
}

void srt_quick(char **a, int lo, int hi) {
    if(lo < hi) {
        int p = part(a, lo, hi);
        srt_quick(a, lo, p);
        srt_quick(a, p+1, hi);
    }
}
