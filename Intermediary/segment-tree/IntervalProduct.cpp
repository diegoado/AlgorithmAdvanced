/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * UVA - Online Judge
 * Problem: 12532 - Interval Product
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <math.h>
#include <iostream>

using namespace std;

// Variable to represent an segment tree.
int *tree;

// Function to construct segment tree from given array.
void build(int *arr, int left, int right, int node=1) {
    if (left == right) {
        tree[node] = arr[left];
    } else {
        int mid;
        mid = (left + right) / 2;

        build(arr, left, mid, node * 2);
        build(arr, mid + 1, right, node * 2 + 1);

        tree[node] = tree[node * 2] * tree[node * 2 + 1];
    }
}

// The function to update a value in input array and segment tree.
void update(int left, int right, int pos, int value, int node=1) {
    if (left == right) {
        tree[node] = value;
    } else {
        int mid;
        mid = (left + right) / 2;

        if (pos <= mid) {
            update(left, mid, pos, value, node * 2);
        } else {
            update(mid + 1, right, pos, value, node * 2 + 1);
        }
        tree[node] = tree[node * 2] * tree[node * 2 + 1];
    }
}

// Return product of elements in range from index i (query start) to j (query end).
int product(int left, int right, int i, int j, int node = 1) {
    if (right < i || left > j) {
        return 1;
    } else if (left >= i && right <= j) {
        return tree[node];
    } else {
        int mid;
        mid = (left + right) / 2;

        return product(left, mid, i, j, node * 2) * product(mid + 1, right, i, j, node * 2 + 1);
    }
}

int main() {
    int n, q;
    int i, j, v, result;

    while (cin >> n >> q) {
        //Height of segment tree
        int height = (int) ceil(log2(n + 1));

        //Maximum size of segment tree
        int max_size = 2 * (int) pow(2, height) - 1;

        // Allocate memory
        tree = new int[max_size];

        int arr[n + 1];
        for (int k = 1; k <= n; k++) {
            scanf("%d", &arr[k]);
            if (arr[k] > 0) {
                arr[k] = 1;
            } else if (arr[k] < 0) {
                arr[k] = -1;
            }
        }
        build(arr, 1, n);

        char type;
        for (int k = 0; k < q; k++) {

            scanf(" %c", &type);
            if (type == 'C') {
                scanf("%d %d", &i, &v);

                if (v > 0) {
                    v = 1;
                } else if (v < 0) {
                    v = -1;
                }
                update(1, n, i, v);
            } else {
                scanf("%d %d", &i, &j);
                   result = product(1, n, i, j);

                if (result > 0)
                    printf("+");
                else if (result < 0)
                    printf("-");
                else
                    printf("0");
            }
        }
        printf("\n");
        delete [] tree;
    }
    return 0;
}