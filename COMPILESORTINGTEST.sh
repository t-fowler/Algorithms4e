#!/bin/bash

gcc cSortUtil.c cInsertionsort.c cMergesort.c cQuicksort.c cShellsort.c sorting_test.c -o sorting_test -lm
