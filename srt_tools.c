#include "srt_tools.h"

int cmp(char *a, char *b) {
    int i = 0;
    while(a[i] != '\0' && b[i] != '\0') {
        if(a[i] > b[i])
            return 1;
        if(a[i] < b[i])
            return 0;
        ++i;
    }
    //При равенстве двух строк
    if(a[i] == b[i])
        return 0;
    //Здесь "for" < "fork"
    if(a[i] == '\0')
        return 0;
    return 1;
}

void swp(char **x, char **y) {
    char *cur = *x;
    *x = *y;
    *y = cur;
}
