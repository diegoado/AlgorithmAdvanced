/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 220B - B. Little Elephant and Array
 * Time limit per test: 4 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <algorithm>

#define MAX 100001

using namespace std;

// Array that contains the numbers x exist, such that number x occurs exactly x times among numbers in query (L, R).
int xoccurs[MAX];

// Array that counts the occurs of a number x in the query (L, R).
int ncont[MAX], ncheck[MAX];

// Variable to represent block size. This is made global so compare() of sort can use it.
int block;

// Variable that representing the current answer to one query
int answer = 0;

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

void add(int* arr, int pos)
{
    if (arr[pos] < MAX)
    {
        ncont[arr[pos]]++;
        if (ncont[arr[pos]] == arr[pos]) {
            answer++;
            ncheck[arr[pos]] = 1;
        } else if (ncheck[arr[pos]]) {
            answer--;
            ncheck[arr[pos]] = 0;
        }
    }
}

void remove(int* arr, int pos)
{
    if (arr[pos] < MAX)
    {
        ncont[arr[pos]]--;
        if (ncont[arr[pos]] == arr[pos]) {
            answer++;
            ncheck[arr[pos]] = 1;
        } else if (ncheck[arr[pos]]) {
            answer--;
            ncheck[arr[pos]] = 0;
        }
    }
}

/* Compute how many numbers x exist, such that number x occurs exactly x times among numbers in query (L, R)
 *
 * arr[] is a sequence of n numbers a1, a2, ..., an.
 * n is size of array a[].
 * query[] is a sequence of m queries, where a query is a pair of numbers (L, R).
 * q is size of array q[].
 */
void existenceCount(int *arr, int n, Query *query, int q)
{
    // Find block size
    block = (int) sqrt(n);

    // Sort all queries so that queries of same blocks are arranged together.
    sort(query, query + q, compare);

    // Initialize current L and current R.
    int currL = 0, currR = 0;

    // Traverse through all queries
    for (int i=0; i<q; i++)
    {
        // L and R values of current range
        int L = query[i].L, R = query[i].R;

        // Remove extra elements of previous range.
        while (currL < L)
        {
            remove(arr, currL);
            currL++;
        }
        // Add Elements of current Range.
        while (currL > L)
        {
            add(arr, currL-1);
            currL--;
        }
        while (currR <= R)
        {
            add(arr, currR);
            currR++;
        }
        // Remove elements of previous range.
        while (currR > R+1)
        {
            remove(arr, currR-1);
            currR--;
        }
        xoccurs[query[i].pos] = answer;
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

    existenceCount(arr, n, query, q);
    for (int k = 0; k < q; k++)
    {
        printf("%d\n", xoccurs[k]);
    }
    return 0;
}