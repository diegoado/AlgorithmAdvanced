#include <bits/stdc++.h>

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

        build(arr, node * 2, left, mid);
        build(arr, node * 2 + 1, mid + 1, right);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
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
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

// Return sum of elements in range from index i (query start) to j (query end).
int sum(int left, int right, int i, int j, int node = 1) {
    if (left > j || right < i) {
        return 0;
    } else if (left >= i && right <= j) {
        return tree[node];
    } else {
        int mid;
        mid = (left + right) / 2;

        return sum(left, mid, i, j, node * 2) + sum(mid + 1, right, i, j, node * 2 + 1);
    }
}