/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Multiples of Three
 * Problem: MULTQ3 - Inversion Count
 * Time limit per test: 0.169 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define MOD 3
#define MAX_NODE 800016

using namespace std;

struct Node {
    int count[3] = {0}, lazy = 0;
};

// Variables to represent the segment tree
Node tree[MAX_NODE];

void propagate(int node) {
    tree[node].lazy %= MOD;

    if (tree[node].lazy == 1) {
        swap(tree[node].count[0], tree[node].count[2]);
        swap(tree[node].count[1], tree[node].count[2]);
    } else if (tree[node].lazy == 2) {
        swap(tree[node].count[0], tree[node].count[1]);
        swap(tree[node].count[1], tree[node].count[2]);
    }
    tree[2 * node].lazy += tree[node].lazy;
    tree[2 * node + 1].lazy += tree[node].lazy;
    tree[node].lazy = 0;
}

void create(int left, int right, int node=1) {
    if (left == right) {
        tree[node].count[0] = 1;
    } else {
        int mid = (left + right) / 2;

        create(left, mid, 2 * node);
        create(mid + 1, right, 2 * node + 1);
        tree[node].count[0] = tree[2 * node].count[0] + tree[2 * node + 1].count[0];
    }
}

void update(int left, int right, int i, int j, int node=1) {
    if (left > right || left > j || right < i)
        return;

    if (left >= i && right <= j) {
        tree[node].lazy += 1;
        propagate(node);
    } else {
        if (tree[node].lazy)
            propagate(node);

        int mid = (left + right) / 2;
        int leftNode = 2 * node, rightNode = 2 * node + 1;

        update(left, mid, i, j, 2 * node);
        update(mid + 1, right, i, j, 2 * node + 1);

        propagate(leftNode);
        propagate(rightNode);
        for (int k = 0; k < MOD; k++) {
            tree[node].count[k] = tree[leftNode].count[k] + tree[rightNode].count[k];
        }
    }
}

int query(int left, int right, int i, int j, int node=1) {
    if (left > right || left > j || right < i)
        return 0;

    if (left >= i && right <= j) {
        propagate(node);
        return tree[node].count[0];
    }
    if (tree[node].lazy)
        propagate(node);

    int mid = (left + right) / 2;
    int leftNode = 2 * node, rightNode = 2 * node + 1;
    return query(left, mid, i, j, leftNode) + query(mid + 1, right, i, j, rightNode);
}

int main() {
    int n, q;
    int c, i, j;
    scanf("%d %d", &n, &q);

    create(1, n);
    for (int k = 0; k < q; k++) {
        scanf("%d %d %d", &c, &i, &j);
        if (c == 0) {
            update(1, n, i + 1, j + 1);
        } else {
            printf("%d\n", query(1, n, i + 1, j + 1));
        }
    }
    return 0;
}
