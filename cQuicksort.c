#include <stdlib.h>
#include <time.h>
#include "cQuicksort.h"
#include "cSortUtil.h"

/* partition a such that a[lo...lt] < a[j] = a[lt...gt] < a[gt...hi] */
static int _partition(int a[], int N, int lo, int hi)
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

/* a method to test the partition algorithm in quick_sort */
static int _test_partition(int a[], int N)
{
    time_t t;
    srand((unsigned) time(&t));
    int pivot = rand() % N;
    _exchange(a, 0, pivot); /* isolate pivot */

    pivot = _partition(a, N, 0, N-1);
    printf("The pivot is in position %d.\n\n", pivot);
    for (int i = 0; i < N; i++) {
        if (i < pivot) {
            return a[i] > a[pivot];
        } 
        else if (i > pivot) {
            return a[i] < a[pivot];
        }
    }
    return 0;
}

/* see comments for quick_sort() below */
void _quick_sort(int a[], int N, int lo, int hi)
{
    /* base case */
    if (N == 1) return;
    if (lo >= hi) return;

    /* pick a random pivot that will belong in a[j] */
    time_t t;
    srand((unsigned) time(&t));
    int pivot = rand() % N;
    _exchange(a, lo, pivot); /* isolate pivot */

    /* partition a such that a[lo...lt] < a[pivot] = a[lt...gt] < a[gt...hi] */
    pivot = _partition(a, N, lo, hi);

    printf("Partitioned array:\n");
    print_ints(a, N);
    printf("\n");
    
    /* recurse on the partitions on either side of the pivot */
    
    printf("left Subarray:\n");
    print_ints(a + lo, pivot - lo);
    printf("\n");

    _quick_sort(a, pivot - lo, lo, pivot - 1);

    printf("sorted");
    print_ints(a + lo, pivot - lo);
    printf("\n");
    
    printf("Right Subarray:\n");
    print_ints(a + pivot + 1, hi - pivot);
    printf("\n");

    _quick_sort(a, hi - pivot, pivot +1, hi);

    printf("sorted\n");
    print_ints(a + pivot + 1, hi - pivot);
    printf("\n");
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