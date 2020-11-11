#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cSortUtil.h"
#include "cMergesort.h"
#include "cQuicksort.h"
#include "cShellsort.h"
#include "cInsertionsort.h"

/* test_routine returns the clock cycles required by *sort_routine */
clock_t test_routine(void (*sort_routine)(int[], int), int a[], int N)
{
    int copy[MAX_INPUT_SIZE];
    copy_ints(a, copy, N);

    clock_t  start = clock();
    sort_routine(copy, N);
    clock_t finish = clock(); 
    
    if (is_sorted(copy, N))
    {
        /* printf("OUTPUT:\n");
        print_ints(copy, N); */
        return finish - start;
    }
    printf("ERROR: array is not sorted.\n\n");
    return -1;
}

int main(int argc, char *argv[])
{
    /* invalid argument list */
    if (argc == 1) {
        printf("Please use a flag to indicate what test to run.\n"
                "-i: insertion test\n"
                "-m: mergesort test\n"
                "-q: quicksort test\n"
                "-s: shellsort test\n"
                "-c: comparison test\n"
                "-d: doubling test\n");
        return 1;
    } else if (argc > 8) {
        printf("Too many arguments. Run man sorting_test for help.\n");
        return 1;
    }
    /* initialize test settings */
    int insertion = 0, merge = 0, quick = 0, shell = 0, 
    compare = 0, doubling = 0;
    char c;
    while (--argc > 0 && (*++argv)[0] == '-')
    { /* I believe this is the idiom from K&R */
        while (c = *++argv[0]) {
            switch (*argv[0]) {
            case 'i':
                insertion = 1;
                break;
            case 'm':
                merge = 1;
                break;
            case 'q':
                quick = 1;
                break;
            case 's':
                shell = 1;
                break;
            case 'c':
                compare = 1;
                break;
            case 'd':
                doubling = 1;
                break;
            default:
                printf("invalid arguments. Run man sorting_test for help.\n");
                return 1;
                break;
            }
        }
    }
    if ( !(merge || quick || shell || insertion) ) {
        printf( "At least 1 sorting test must be chosen.\n"
                "-i: insertion test\n"
                "-m: mergesort test\n"
                "-q: quicksort test\n"
                "-s: shellsort test\n");
        return 1;
    }
    
    /* printf("INPUT:\n"); */
    int a[MAX_INPUT_SIZE];
    int N = read_ints(a);
    /* print_ints(a, N); */

    while (insertion + merge + quick + shell + compare + doubling) {
        if (merge) {
            int copy[MAX_INPUT_SIZE];
            copy_ints(a, copy, N);

            /* printf("COPY:\n");
            print_ints(copy, N);

            clock_t start = clock();
            merge_sort(copy, N);
            clock_t finish = clock();
            
            printf("OUTPUT:\n");
            print_ints(copy, N);
            printf("mergesort:\n%d\n\n", (int) (finish - start)); */
            
            printf("mergesort:\n%d\n\n", 
            (int) test_routine(merge_sort, a, N));
            merge = 0;
        }
        else if (insertion) {
            printf("insertionsort:\n%d\n\n", 
            (int) test_routine(insertion_sort, a, N));
            insertion = 0;  /* reset flag */
        }
        else if (quick) {
            printf("quicksort:\n%d\n\n", 
            (int) test_routine(quick_sort, a, N));  
            quick = 0;  /* reset flag */
            printf("made it.\n");
        }
        else if (shell) {
           printf("shellsort:\n%d\n\n", 
            (int) test_routine(shell_sort, a, N));   
            shell = 0; /* reset flag */
        }
        else if (compare) {
            printf("comparison test\n");
            compare = 0;
        }
        else if (doubling) {
            printf("doubling test\n");
            doubling--;
        }
    }
}