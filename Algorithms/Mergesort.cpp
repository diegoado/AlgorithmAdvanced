
// Function to merge the two haves arr[l..mid] and arr[mid+1..r] of array arr[]
void merge(int *arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int i = 0, j = 0, k = l;

    // Create temp arrays
    int left[n1], right[n2];

    // Copy data to temp arrays arr[l..mid] and arr[mid+1..r]
    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + j + 1];

    // Merge the temp arrays back into arr[l..r]
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        // Sort first and second halves
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        // Merge the two halves into arr
        merge(arr, l, mid, r);
    }
}