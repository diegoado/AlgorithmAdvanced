/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * UVA - Online Judge
 * Problem: 11297 - Census
 * Time limit per test: 8 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <math.h>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

// Variable to represent an segment tree.
pair<int, int>** tree;

// Function to construct segment tree from given array.
void build(int *arr, int left, int right, int level, int node=1) {
    if (left == right) {
        tree[level][node].first = arr[left];
        tree[level][node].second = arr[right];
    } else {
        int mid;
        mid = (left + right) / 2;

        build(arr, left, mid, level, node * 2);
        build(arr, mid + 1, right, level, node * 2 + 1);

        tree[level][node].first  = max(tree[level][node * 2].first, tree[level][node * 2 + 1].first);
        tree[level][node].second = min(tree[level][node * 2].second, tree[level][node * 2 + 1].second);
    }
}

// The function to update a value in input array and segment tree.
void update(int left, int right, int level, int pos, int value, int node=1) {
    if (left == right) {
        tree[level][node].first = value;
        tree[level][node].second = value;
    } else {
        int mid;
        mid = (left + right) / 2;

        if (pos <= mid) {
            update(left, mid, level, pos, value, node * 2);
        } else {
            update(mid + 1, right, level, pos, value, node * 2 + 1);
        }
        tree[level][node].first  = max(tree[level][node * 2].first, tree[level][node * 2 + 1].first);
        tree[level][node].second = min(tree[level][node * 2].second, tree[level][node * 2 + 1].second);
    }
}

// Return pair that contains the maximum and a minimum between range from index i (query start) to j (query end).
pair<int, int> query(int left, int right, int level, int i, int j, int node = 1) {
    pair<int, int> result = make_pair(INT_MIN, INT_MAX);

    if (left > j || right < i) {
        return result;
    } else if (left >= i && right <= j) {
        return tree[level][node];
    } else {
        int mid;
        mid = (left + right) / 2;
        if (right <= mid)
            return query(left, mid, level, i, j, node * 2);
        else if (left > mid)
            return query(mid + 1, right, level, i, j, node * 2 + 1);

        pair<int, int> lNode = query(left, mid, level, i, j, node * 2);
        pair<int, int> rNode = query(mid + 1, right, level, i, j, node * 2 + 1);

        result.first  = max(lNode.first, rNode.first);
        result.second = min(lNode.second, rNode.second);

        return result;
    }
}

int main() {
    int n, q;
    scanf("%d", &n);

    // Height of segment tree
    int height = (int) ceil(log2(n + 1));

    // Maximum size of segment tree
    int max_size = 2 * (int) pow(2, height) - 1;

    tree = new pair<int, int>*[n + 1];

    // Allocate memory
    for (int i = 1; i <= n; i++) {
        tree[i] = new pair<int, int>[max_size];

        int arr[n + 1];
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[j]);
        }
        build(arr, 1, n, i);
    }

    char type;
    int row, column, value;
    int upper, left, lower, right;

    scanf("%d", &q);
    for (int k = 0; k < q; k++) {
        scanf(" %c", &type);

        if (type == 'c') {
            scanf("%d %d %d", &row, &column, &value);
            update(1, n, row, column, value);
        } else {
            scanf("%d %d %d %d", &lower, &left, &upper, &right);
            pair<int, int> r2, r1 = make_pair(INT_MIN, INT_MAX);

            for (int i = lower; i <= upper; i++) {
                r2 = query(1 , n, i, left, right);

                r1.first  = max(r1.first, r2.first);
                r1.second = min(r1.second, r2.second);
            }
            printf("%d %d\n", r1.first, r1.second);
        }
    }
    return 0;
}


