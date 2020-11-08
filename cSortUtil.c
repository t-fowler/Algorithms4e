#include <stdio.h>
#include "cSortUtil.h"

/* exchange the values of 2 ints in an array */
void _exchange(int a[], int x, int y)
{
    int tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

/* For testing sorting algorithms */
bool is_sorted(int a[], int N) {
    for (int i = 0; i < N - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}

/* reads from the standard input and stores into an integer array */
int read_ints(int *a)
{
    int N = 0;
    int i = 0;
    while (i < MAX_INPUT_SIZE && scanf("%d", a + i++) != EOF) {
        N++;
    }
    return N;
}

/* prints an array of ints */
void print_ints(int a[], int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}
