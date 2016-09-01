/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: To Poland
 * Time limit per test: 0.106 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

// Variable to represent an segment tree.
int *tree;
// Variable to storage the answer for a test case.
vector<int> balloons;

// Function to construct segment tree from given array.
void build(int *arr, int left, int right, int node=1) {
    if (left == right) {
        tree[node] = arr[left];
    } else {
        int mid;
        mid = (left + right) / 2;

        build(arr, left, mid, node * 2);
        build(arr, mid + 1, right, node * 2 + 1);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
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
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}

// Return max of elements in range from index i (query start) to j (query end).
int query(int left, int right, int i, int j, int node = 1) {
    if (right < i || left > j) {
        return 0;
    } else if (left >= i && right <= j) {
        return tree[node];
    } else {
        int mid;
        mid = (left + right) / 2;

        return max(query(left, mid, i, j, node * 2), query(mid + 1, right, i, j, node * 2 + 1));
    }
}

int main() {
    char form;
    int t, n, m, q, c = 0;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &m);

        // Height of segment tree
        int height = (int) ceil(log2(n + 1));

        // Maximum size of segment tree
        int max_size = 2 * (int) pow(2, height) - 1;

        // Allocate memory
        tree = new int[max_size];

        int arr[n + 1];
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);

        int k, i, r;
        build(arr, 1, n);

        scanf("%d", &q);
        for (int j = 0; j < q; j++) {
            scanf(" %c", &form);
            if (form == 'A') {
                scanf("%d", &k);
                m += k;
            } else if (form == 'B') {
                scanf("%d %d", &i, &k);
                update(1, n, i + 1, k);
            } else {
                scanf("%d %d", &i, &k);
                r = query(1, n, i + 1, k + 1);
                balloons.push_back(abs(m - r));
            }
        }
        printf("Testcase %d:\n", c);
        for (int j = 0; j < balloons.size(); j++) {
            printf("%d\n", balloons[j]);
        }

        c++;
        if (c == q)
            printf("\n");

        delete [] tree;
        balloons.clear();
    }
    return 0;
}
