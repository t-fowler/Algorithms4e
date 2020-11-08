#ifndef CMERGESORT_H
#define CMERGESORT_H

void insertion_sort(int a[], int N);

static void _merge(int a[], int low, int mid, int hi);

void _merge_sort(int a[], int N, int low, int hi);

void merge_sort(int a[], int N);

#endif