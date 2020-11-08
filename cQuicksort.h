#ifndef CQUICKSORT_H
#define CQUICKSORT_H

static int _partition(int a[], int N, int lo, int hi);

static int _test_partition(int a[], int N);

void _quick_sort(int a[], int N, int lo, int hi);

void quick_sort(int a[], int N);

#endif