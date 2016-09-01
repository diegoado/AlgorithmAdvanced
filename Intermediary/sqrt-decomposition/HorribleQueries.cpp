/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de AraÃºjo
 * Registry: 113210090
 * Discipline: Algoritmos AvanÃ§ados
 *
 * Spoj - Online Judge
 * Problem: Horrible Queries
 * Time limit per test: 2.329 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <cmath>
#include <cstdio>
#include <cstring>

typedef long long int llong;

using namespace std;

// Variable to represent group size.
int len;

void update(llong *arr, llong *groups, llong *lazy, int p, int q, llong value)
{
    int l = p / len, r = q / len;

    if (l == r) {
        for (int k = p; k <= q; k++) {
            arr[k] += value;
            groups[k / len] += value;
        }
    } else {
        for (int k = p; k <= (l + 1) * len - 1; k++) {
            arr[k] += value;
            groups[k / len] += value;
        }
        for (int k = l + 1; k <= r - 1; k++) {
            lazy[k] += value;
            groups[k] += value * len;
        }
        for (int k = r * len; k <= q; k++) {
            arr[k] += value;
            groups[k / len] += value;
        }
    }
}

llong sum(llong *arr, llong *groups, llong *lazy, int i, int j)
{
    llong sum = 0;
    int l = i / len, r = j / len;

    if (l == r) {
        for (int k = i; k <= j; k++)
            sum += arr[k] + lazy[k / len];
    } else {
        for (int k = i; k <= (l + 1) * len - 1; k++)
            sum += arr[k] + lazy[k / len];
        for (int k = l + 1; k <= r - 1; k++)
            sum += groups[k];
        for (int k = r * len; k <= j; k++)
            sum += arr[k] + lazy[k / len];
    }
    return sum;
}

int main() {
    int t, n, m;

    scanf("%d", &t);
    for (int k = 0; k < t; k++)
    {
        scanf("%d %d", &n, &m);

        // Variable that contains all cows lined up in a row from 1 to N.
        llong arr[n];
        memset(arr, 0, sizeof(arr));

        double l = sqrt(n);
        len = (int) ceil(n / l);

        // Variable that contains the sum of all cows in the same group.
        llong groups[len];
        memset(groups, 0, sizeof(groups));
        // Variable the contains the lazy updates for each cow's group.
        llong lazy[len];
        memset(lazy, 0, sizeof(lazy));

        for (int j = 0; j < m; ++j)
        {
            int c;
            scanf(" %d", &c);

            if (c == 0) {
                int p, q, v;
                scanf("%d %d %d", &p, &q, &v);
                update(arr, groups, lazy, fmax(0, p-1), fmin(n-1, q-1), v);
            } else {
                int p, q;
                scanf("%d %d", &p, &q);
                printf("%lld\n", sum(arr, groups, lazy, fmax(0, p-1), fmin(n-1, q-1)));
            }
        }
    }
    return 0;
}
