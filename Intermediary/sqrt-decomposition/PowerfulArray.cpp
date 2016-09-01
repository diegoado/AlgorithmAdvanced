/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 86D - D. Powerful Array
 * Time limit per test: 5 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <algorithm>

#define MAX_N 200000
#define MAX_A 1000001

typedef long long int llong;

using namespace std;

// Array that contains the power of the subarray the sum of products Ks for every positive integer s into the subarray.
llong soccurs[MAX_N];

// Array that counts the occurs of a number s in the query (L, R).
int ncont[MAX_A];

// Variable to represent block size. This is made global so compare() of sort can use it.
int block;

// Variable that representing the current answer to one query
llong answer = 0;

// Structure to represent a query range.
struct Query
{
    int L, R, pos;
};

/* Function used to sort all queries so that all queries of same block are arranged together and within a block,
 * queries are sorted in increasing order of R values.
 */
bool compare(Query x, Query y)
{
    // Different blocks, sort by block.
    if (x.L/block != y.L/block)
        return x.L/block < y.L/block;

    // Same block, sort by R value
    return x.R < y.R;
}

void add(int* a, int pos)
{
    answer += a[pos] * ((ncont[a[pos]] << 1) + 1);
    ncont[a[pos]]++;
}

void remove(int* a, int pos)
{
    answer -= a[pos] * ((ncont[a[pos]] << 1) - 1);
    ncont[a[pos]]--;
}

/* Compute the power sum at a products subarray Ks for every integer s the i-th query.
 *
 * a[] is a sequence of n numbers a1, a2, ..., an.
 * n is size of array a[].
 * q[] is a sequence of m queries, where a query is a pair of numbers (L, R).
 * m is size of array q[].
 */
void powerProductsSum(int *a, int n, Query *q, int m)
{
    // Find block size
    block = (int) sqrt(n);

    // Sort all queries so that queries of same blocks are arranged together.
    sort(q, q + m, compare);

    // Initialize current L and current R.
    int currL = 0, currR = 0;

    // Traverse through all queries
    for (int i=0; i<m; i++)
    {
        // L and R values of current range
        int L = q[i].L, R = q[i].R;

        // Remove extra elements of previous range.
        while (currL < L)
        {
            remove(a, currL);
            currL++;
        }
        // Add Elements of current Range.
        while (currL > L)
        {
            add(a, currL-1);
            currL--;
        }
        while (currR <= R)
        {
            add(a, currR);
            currR++;
        }
        // Remove elements of previous range.
        while (currR > R+1)
        {
            remove(a, currR-1);
            currR--;
        }
        soccurs[q[i].pos] = answer;
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int l, r;
    Query query[q];
    for (int j = 0; j < q; j++)
    {
        scanf("%d %d", &l, &r);

        query[j].pos = j;
        query[j].L = l-1, query[j].R = r-1;
    }

    powerProductsSum(arr, n, query, q);
    for (int k = 0; k < q; k++)
    {
        cout << soccurs[k] << endl;
    }
    return 0;
}

