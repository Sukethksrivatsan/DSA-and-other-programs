
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRandoms(int size)
{
    // size = 10; // uncomment for debugging
    long long lower = 1, upper =    9223372036854775800;
    // upper = 10; // uncomment for debugging
    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        long long num = (rand() % (upper - lower + 1)) + lower;
        printf("%lld ", num);
    }
    printf("\n");
    return;
}

int main(int argc, char const *argv[])
{
    unsigned int seed = 0;

    srand(time(0));

    printf("19\n");
    for (int size = 100000; size <= 1000000; size += 50000) {
        printRandoms(size);
    }

    return 0;
}
