#include "cSortUtil.h"
#include "cMergesort.h"
#include "cInsertionsort.h"

/*********************************************
 * _merge takes 2 sequential sorted sections *
 * of an array and merges them into 1 sorted *
 * section in the same index range.          *
 * _merge is for use in merge_sort           * 
 *********************************************/
static void _merge(int a[], int low, int mid, int hi) 
{
    static int aux[MAX_INPUT_SIZE];
    int N =  hi - low + 1;
    int i; /* tracks next position */
    int j; /* tracks left side */
    int k; /* tracks right side */
    
    /* Merge into auxilary array */
    for (i = low, j = low, k = mid + 1; i < low + N;) {
        if      (j > mid)       aux[i++] = a[k++];
        else if (k > hi)        aux[i++] = a[j++];
        else if (a[j] <= a[k])  aux[i++] = a[j++];
        else                    aux[i++] = a[k++];
    }
    /* Copy back into a */
    for (i = low; i < low + N; i++) {
        a[i] = aux[i]; 
    }
}

/* See the comments for merge_sort() below */
void _merge_sort(int a[], int N, int low, int hi) 
{
    if (low > hi) {
        return;
    }
    if (N <= 3) {
        insertion_sort(a + low, N);
        return;
    }
    int mid = (hi + low) / 2 ;
    _merge_sort(a, mid - low + 1, low, mid);    /* mid inclusive */
    _merge_sort(a, hi - mid, mid + 1, hi );     /* mid not inclusive */
    _merge(a, low, mid,  hi);
}

/*************************************************
 * merge_sort is hopefully an N * logN int sort. *
 *                                               *
 * int a[]  - the set must start at index 1.     *
 * int N    - the size of the set to be sorted.  *
 *************************************************/
void merge_sort(int a[], int N)
{
    _merge_sort(a, N, 0, N - 1);
}