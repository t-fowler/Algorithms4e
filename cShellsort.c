#include <stdlib.h>
#include <math.h>
#include "cShellsort.h"
#include "cSortUtil.h"

/* h-sort an array with a decreasing value of h */
void shell_sort(int a[], int N)
{
    int h = 1;  /* 1, 4, 13, 40, 121, ... */
    for (int i = 1; h < N/3; i++)
        h = (pow((double) 3, (double) i) - 1) / 2;

    while (h >= 1) {
        /* h-sort the array */
        for (int i = h; i < N; i++) {
            /* bubble a[i] down through a[i - h], a[i - 2h], ... */
            for (int j = i; j <= h; j -=h) {
                if (a[j] < a[j - h])
                    _exchange(a, j, j - h);
            }
        }
        h /= 3;
    }
}