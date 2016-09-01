/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: Can you answer these queries III
 * Time limit per test: 0.330 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <cstdio>
#include <climits>
#include <algorithm>

typedef long long int llong;

using namespace std;

struct Node {
    llong full, best, left, right;
};

// Variable to represent an segment tree.
Node* tree;

// Function to construct segment tree from given array.
void build(int *arr, int left, int right, int node=1) {
    if (left == right) {
        tree[node].full  = arr[left];
        tree[node].best  = arr[left];
        tree[node].left  = arr[left];
        tree[node].right = arr[left];
    } else {
        int mid;
        mid = (left + right) / 2;

        build(arr, left, mid, node * 2);
        build(arr, mid + 1, right, node * 2 + 1);

        tree[node].full  = tree[node * 2].full + tree[node * 2 + 1].full;
        tree[node].left  = max(tree[node * 2].left, tree[node * 2].full + tree[node * 2 + 1].left);
        tree[node].right = max(tree[node * 2 + 1].right, tree[node * 2 + 1].full + tree[node * 2].right);
        tree[node].best  = max(tree[node].left,
                               max(tree[node].right,
                                   max(tree[node * 2].best,
                                       max(tree[node * 2 + 1].best, tree[node * 2].right + tree[node * 2 + 1].left))));
    }
}

// The function to update a value in input array and segment tree.
void update(int left, int right, int pos, int value, int node=1) {
    if (left == right) {
        tree[node].full  = value;
        tree[node].best  = value;
        tree[node].left  = value;
        tree[node].right = value;
    } else {
        int mid;
        mid = (left + right) / 2;

        if (pos <= mid) {
            update(left, mid, pos, value, node * 2);
        } else {
            update(mid + 1, right, pos, value, node * 2 + 1);
        }
        tree[node].full  = tree[node * 2].full + tree[node * 2 + 1].full;
        tree[node].left  = max(tree[node * 2].left, tree[node * 2].full + tree[node * 2 + 1].left);
        tree[node].right = max(tree[node * 2 + 1].right, tree[node * 2 + 1].full + tree[node * 2].right);
        tree[node].best  = max(tree[node].left,
                               max(tree[node].right,
                                   max(tree[node * 2].best,
                                       max(tree[node * 2 + 1].best, tree[node * 2].right + tree[node * 2 + 1].left))));
    }
}

Node query(int left, int right, int i, int j, int node = 1) {
    Node result;
    result.full = result.best = result.left = result.right = INT_MIN / 4;

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

        Node lNode = query(left, mid, i, j, node * 2);
        Node rNode = query(mid + 1, right, i, j, node * 2 + 1);

        result.full  = lNode.full + rNode.full;
        result.left  = max(lNode.left, lNode.full + rNode.left);
        result.right = max(rNode.right, rNode.full + lNode.right);
        result.best  = max(result.left,
                               max(result.right,
                                   max(lNode.best,
                                       max(rNode.best, lNode.right + rNode.left))));

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

    // Allocate memory
    tree = new Node[max_size];

    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    build(arr, 1, n);

    int t, x, y;
    scanf("%d", &q);
    for (int j = 0; j < q; j++) {
        scanf("%d %d %d", &t, &x, &y);

        if (t == 0) {
           update(1, n, x, y);
        } else {
            Node result = query(1, n, x, y);
            printf("%lld\n", result.best);
        }
    }
}

