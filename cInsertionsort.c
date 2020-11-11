#include "cSortUtil.h"

/* a simple sorting algorithm that works like sorting a card hand */
void insertion_sort(int a[], int N)
{
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j] < a[j-1]) 
                _exchange(a, j, j-1);
        }
    }
}