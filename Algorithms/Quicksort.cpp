#include <algorithm>

using namespace std;

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
   array. */
int partition(int *arr, int l, int r)
{
    int pivot = arr[r]; // arr[h] is the pivo
    int i = l - 1;

    for (int j = l; j <= r - 1; j++)
    {
        // Changing this to sorted in ascendant or descendant order.
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quicksort(int *arr, int l, int r)
{
    if (l < r) {
        int mid = partition(arr, l, r);

        quicksort(arr, l, mid - 1);
        quicksort(arr, mid + 1, r);
    }
}
