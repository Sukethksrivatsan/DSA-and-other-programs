#include <stdlib.h>
#define ll long long


void merge(ll arr[], ll l, ll m, ll r, ll *number_of_comparisions)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 = r - m;

    // ll L[n1], R[n2];

    ll *L = malloc((n1) * sizeof (long long));
    ll *R = malloc((n2) * sizeof (long long));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        (*number_of_comparisions)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(ll arr[], ll l, ll r, ll *number_of_comparisions)
{
    if (l < r) {
        ll m = l + (r - l) / 2;

        mergeSort(arr, l, m, number_of_comparisions);
        mergeSort(arr, m + 1, r, number_of_comparisions);

        merge(arr, l, m, r, number_of_comparisions);
    }
}
