#include <stdio.h>
#include "cSortUtil.h"
#include "cMergesort.h"

#if defined(DEBUG)
int numberfreq[NUMBER_RANGE];
#endif

int main(int argc, char *argv[])
{
    int a[MAX_INPUT_SIZE];
    int N = read_ints(a);

#if defined(DEBUG)
    for (int i = 0; i < N; i++)
        numberfreq[ a[i] ]++;
#endif

    print_ints(a, N);
    merge_sort(a, N);
    print_ints(a, N);

#if defined(DEBUG)
    for (int i = 0; i < N; i++)
        numberfreq[ a[i] ]--;
    for (int i = 0; i < N; i++) {
        if (numberfreq[i] != 0) {
            printf("Error in Mergesort: Not the same array.\n");
            return 1;
        }
    }
#endif

if (!is_sorted(a, N)) {
    printf("Error in Mergesort: Array not sorted.\n");
    return 1;
}
return 0;
}