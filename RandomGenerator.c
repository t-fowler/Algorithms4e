#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXOUTPUTS 10000

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    time_t t;
    int a[MAXOUTPUTS];
    srand((unsigned) time(&t));

    printf("%d\n",N);
    for (int i = 0; i < N; i++) {
        printf("%d\n", rand() % 100);
    }

    return 0;
}