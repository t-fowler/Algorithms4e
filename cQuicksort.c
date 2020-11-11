#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cQuicksort.h"
#include "cSortUtil.h"
#include "cInsertionsort.h"

/* partition a such that a[lo...lt] < a[j] = a[lt...gt] < a[gt...hi] */
int _partition(int a[], int N, int lo, int hi)
{
    if (lo >= hi) return -1;

    /* partition  the array*/
    int pivot = lo;
    int curr = ++lo;
    while (lo <= hi) {
        if (a[lo] < a[pivot]) {
            _exchange(a, curr++, lo);
        }
        lo++;
    }

    /* place the pivot in its final position */
    _exchange(a, pivot, curr-1);
    return curr - 1;
}

/* see comments for quick_sort() below */
void _quick_sort(int a[], int N, int lo, int hi)
{
    /* base case */
    // if (N == 1) return;
    if (lo >= hi) return;

    /* pick a random pivot that will belong in a[j] */
    time_t t;
    srand((unsigned) time(&t));
    int pivot = (rand() % N) + lo;
    _exchange(a, lo, pivot); /* isolate pivot */

    /* partition a such that a[lo...lt] < a[pivot] = a[lt...gt] < a[gt...hi] */
    pivot = _partition(a, N, lo, hi);

    /* recurse on the partitions on either side of the pivot */
    _quick_sort(a, pivot - lo, lo, pivot - 1);
    _quick_sort(a, hi - pivot, pivot +1, hi);
}

/*************************************************
 * quick_sort is hopefully an N * logN int sort. *
 *                                               *
 * int a[]  - the set must start at index 1.     *
 * int N    - the size of the set to be sorted.  *
 *************************************************/
void quick_sort(int a[], int N)
{
    _quick_sort(a, N, 0, N-1);
}