#define ll long long

void swap(ll* a, ll* b)
{
    ll t = *a;
    *a = *b;
    *b = t;
}

ll partition (ll arr[], ll low, ll high, ll *number_of_comparisions)
{
    ll pivot = arr[high];
    ll i = (low - 1);

    for (ll j = low; j <= high- 1; j++)
    {
        (*number_of_comparisions)++;
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(ll arr[], ll low, ll high, ll *number_of_comparisions)
{
    if (low < high)
    {
        ll pi = partition(arr, low, high, number_of_comparisions);

        quickSort(arr, low, pi - 1, number_of_comparisions);
        quickSort(arr, pi + 1, high, number_of_comparisions);
    }
}
