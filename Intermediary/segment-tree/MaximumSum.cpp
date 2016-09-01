/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: Maximum Sum
 * Time limit per test: 0.357 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <cstdio>
#include <algorithm>

using namespace std;


// Variable to represent an segment tree and store largest and second largest values between A[i] - A[j].
pair<int, int> *tree;

// Function to construct segment tree from given array.
void build(int *arr, int left, int right, int node=1) {
    if (left == right) {
        tree[node].first = arr[left];
        tree[node].second = -1;
    } else {
        int mid;
        mid = (left + right) / 2;

        build(arr, left, mid, node * 2);
        build(arr, mid + 1, right, node * 2 + 1);

        tree[node].first  = max(tree[node * 2].first, tree[node * 2 + 1].first);
        tree[node].second = min(
                max(tree[node * 2].first, tree[node * 2 + 1].second), max(tree[node * 2].second, tree[node * 2 + 1].first));
    }
}

// The function to update a value in input array and segment tree.
void update(int left, int right, int pos, int value, int node=1) {
    if (left == right) {
        tree[node].first = value;
        tree[node].second = -1;
    } else {
        int mid;
        mid = (left + right) / 2;

        if (pos <= mid) {
            update(left, mid, pos, value, node * 2);
        } else {
            update(mid + 1, right, pos, value, node * 2 + 1);
        }
        tree[node].first  = max(tree[node * 2].first, tree[node * 2 + 1].first);
        tree[node].second = min(
                max(tree[node * 2].first, tree[node * 2 + 1].second), max(tree[node * 2].second, tree[node * 2 + 1].first));
    }
}

// Return a Node the contains two elements in range from index i (query start) to j (query end)
// such that the sum arr[i]+ arr[j] is maximized.
pair<int, int> query(int left, int right, int i, int j, int node = 1) {
    pair<int, int> result;
    result.first = result.second = -1;
    if (left > j || right < i) {
        return result;
    } else if (left >= i && right <= j) {
        return tree[node];
    } else {
        int mid;
        mid = (left + right) / 2;
        if (right <= mid)
            return query(left, mid, i, j, node * 2);
        else if (left > mid)
            return query(mid + 1, right, i, j, node * 2 + 1);

        pair<int, int> lNode = query(left, mid, i, j, node * 2);
        pair<int, int> rNode = query(mid + 1, right, i, j, node * 2 + 1);

        result.first  = max(lNode.first, rNode.first);
        result.second = min(
                max(lNode.first, rNode.second), max(lNode.second, rNode.first));

        return result;
    }
}

int main() {
    int n, q;
    scanf("%d", &n);

    //Height of segment tree
    int height = (int) ceil(log2(n));

    //Maximum size of segment tree
    int max_size = 2 * (int) pow(2, height) - 1;

    // Allocate memory
    tree = new pair<int, int>[max_size];

    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    build(arr, 1, n);

    scanf("%d", &q);
    char type;
    int x, y, pos, value;

    pair<int, int> result;
    for (int j = 0; j < q; j++) {

        scanf(" %c", &type);
        if (type == 'U') {
            scanf("%d %d", &pos, &value);
            update(1, n, pos, value);
        } else {
            scanf("%d %d", &x, &y);

            result = query(1, n, x, y);
            printf("%d\n", result.first + result.second);
        }
    }
    return 0;
}