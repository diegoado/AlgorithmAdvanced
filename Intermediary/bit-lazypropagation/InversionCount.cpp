/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: INVCNT - Inversion Count
 * Time limit per test: 3.599 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define MAX_N 200000

using namespace std;

typedef long long ll;

int arr[MAX_N];

ll merge(int temp[], int l, int mid, int r) {
    ll cnt = 0;
    int i, j, k;

    i = l, j = mid, k = l;
    while ((i <= mid - 1) && (j <= r)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            cnt += mid - i;
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];

    for (i=l; i <= r; i++)
        arr[i] = temp[i];

    return cnt;
}

ll mergeSort(int temp[], int left, int right) {
    int mid;
    ll cnt = 0;
    if (right > left) {
        mid = (right + left)/2;

        cnt += mergeSort(temp, left, mid);
        cnt += mergeSort(temp, mid+1, right);
        cnt += merge(temp, left, mid+1, right);
    }
    return cnt;
}

ll countInv(int n) {
    int *temp = (int *) malloc(sizeof(int) *n);
    return mergeSort(temp, 0, n - 1);
}

int main() {
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("%lld\n", countInv(n));
    }
}