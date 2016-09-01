/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: D-Query
 * Time limit per test: 0.227 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <algorithm>

#define MAX_M 200000
#define MAX_N 1000000

using namespace std;

// Initialize the array that contains the distinct numbers for each d-query.
int distinct[MAX_M];
// Initialize the array count the number occurrence for each d-query in array a.
int cont[MAX_N];

// Variable to represent block size. This is made global so compare() of sort can use it.
int block;

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

/* Compute distinct numbers at all query ranges.
 *
 * arr[] is a sequence of n numbers a1, a2, ..., an.
 * n is size of array a[].
 * query[] is a sequence of m queries, where a query is a pair of numbers (L, R).
 * q is size of array query[].
 */
void distinctCount(int *arr, int n, Query *query, int q)
{
    // Find block size
    block = (int) sqrt(n);
    // Sort all queries so that queries of same blocks are arranged together.
    sort(query, query + q, compare);

    // Initialize current L, current R nad current answer
    int currL = 0, currR = 0, currAns = 0;

    // Traverse through all queries
    for (int i=0; i<q; i++)
    {
        // L and R values of current range
        int L = query[i].L, R = query[i].R;

        // Remove extra elements of previous range.
        while (currL < L)
        {
            cont[arr[currL]]--;
            if (cont[arr[currL]] == 0)
                currAns--;

            currL++;
        }
        // Add Elements of current Range.
        while (currL > L)
        {
            cont[arr[currL-1]]++;
            if (cont[arr[currL-1]] == 1)
                currAns++;

            currL--;
        }
        while (currR <= R)
        {
            cont[arr[currR]]++;
            if (cont[arr[currR]] == 1)
                currAns++;

            currR++;
        }
        // Remove elements of previous range.
        while (currR > R+1)
        {
            cont[arr[currR-1]]--;
            if (cont[arr[currR-1]] == 0)
                currAns--;

            currR--;
        }
        distinct[query[i].pos] = currAns;
    }
}

int main() {
    int n, q;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int l, r;
    scanf("%d", &q);

    Query query[q];
    for (int j = 0; j < q; j++)
    {
        scanf("%d %d", &l, &r);

        query[j].pos = j;
        query[j].L = l-1, query[j].R = r-1;
    }

    distinctCount(arr, n, query, q);
    for (int k = 0; k < q; k++)
    {
        printf("%d\n", distinct[k]);
    }
    return 0;
}
