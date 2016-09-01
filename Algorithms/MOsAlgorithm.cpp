/*
 * The idea of MO’s algorithm is to pre-process all queries so that result of one query can be used in next query.
 * Below are step:.
 *
 * Let a[0…n-1] be input array and q[0..m-1] be array of queries.
 *
 * 1. Sort all queries in a way that queries with L values from 0 to √n – 1 are put together,
 *    then all queries from √n to 2*√n – 1, and so on. All queries within a block are sorted in increasing order of R values.
 *
 * 2. Process all queries one by one in a way that every query uses sum computed in previous query.
 *
 *    a) Let ‘sum’ be sum of previous query.
 *    b) Remove extra elements of previous query. For example if previous query is [0, 8] and current query is [3, 9],
 *       then we subtract a[0] and a[1] from sum.
 *    c) Add new elements of current query. In the same example as above, we add a[9] to sum.
 *
 * The great thing about this algorithm is, in step 2, index variable for R change at most O(n * √n) times throughout
 * the run and same for L changes its value at most O(m * √n) times (See below, after the code, for details).
 * All these bounds are possible only because sorted queries first in blocks of √n size.
 *
 * The pre-processing part takes O(m Log m) time.
 *
 * Processing all queries takes O(n * √n) + O(m * √n) = O((m+n) * √n) time.
 */

#include <algorithm>

using namespace std;

// Variable to represent block size. This is made global so compare() of sort can use it.
int block;

// Structure to represent a query range
struct Query
{
    int L, R;
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

/* Prints sum of all query ranges. m is number of queries
 *
 * a[] is a sequence of n numbers a1, a2, ..., an.
 * n is size of array a[].
 * q[] is a sequence of m queries, where a query is a pair of numbers (L, R).
 * m is size of array q[].
 */
void computeQueriesRange(int a[], int n, Query q[], int m)
{
    // Find block size
    block = (int)sqrt(n);

    // Sort all queries so that queries of same blocks are arranged together.
    sort(q, q + m, compare);

    // Initialize current L, current R and current sum
    int currL = 0, currR = 0, currSum = 0;

    // Traverse through all queries
    for (int i=0; i<m; i++)
    {
        // L and R values of current range
        int L = q[i].L, R = q[i].R;

        /* Remove extra elements of previous range. For example if previous range is [0, 3] and current
         * range is [2, 5], then a[0] and a[1] are subtracted
         */
        while (currL < L)
        {
            currSum -= a[currL];
            currL++;
        }

        // Add Elements of current Range
        while (currL > L)
        {
            currSum += a[currL-1];
            currL--;
        }
        while (currR <= R)
        {
            currSum += a[currR];
            currR++;
        }

        /* Remove elements of previous range. For example when previous range is [0, 10] and current range
         * is [3, 8], then a[9] and a[10] are subtracted
         */
        while (currR > R+1)
        {
            currSum -= a[currR-1];
            currR--;
        }

        // Print sum of current range
        printf("%d\n", currSum);
    }
}
