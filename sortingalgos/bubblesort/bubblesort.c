

#include <stdio.h>
#define ll long long

void swap(ll  *a, ll  *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    return;
}


void bubbleSort(ll  array[], ll  size, ll  *number_of_comparisions) {
    short swapped = 0;
    for (int i = 0; i <= size; i++) {
        swapped = 0;
        for (int j = 0; j <= size - i; j++) {
            (*number_of_comparisions)++;
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return;
}
