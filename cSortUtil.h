#ifndef CSORTUTIL_H
#define CSORTUTIL_H

#include <stdbool.h>

#define MAX_INPUT_SIZE 500
#define NUMBER_RANGE 100
#define DEBUG

void _exchange(int a[], int x, int y);

bool is_sorted(int a[], int N);

int read_ints(int *a);

void print_ints(int a[], int N);

#endif