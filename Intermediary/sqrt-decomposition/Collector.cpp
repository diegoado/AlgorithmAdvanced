/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * OBI 2016
 * Problem: Catador
 * Time limit per test: unknown seconds
 * Memory limit per test: unknown megabytes
 * Input: standard input
 * Output: standard output
 */

#include <cstdio>
#include <algorithm>
#include <cstring>

typedef long long int llong;

using namespace std;

// Variable to represent group size.
int len;


void update(int *buckets, int *groups, int lower, int upper)
{
    int l, r;
    l = lower / len, r = upper / len;

    if (l == r) {
        for (int k = lower; k <= upper; k++) {
            if (buckets[k] > 0)
                buckets[k]--;
        }
    } else {
        for (int k = lower; k <= (l + 1) * len - 1; k++) {
            if (buckets[k] > 0)
                buckets[k]--;
        }
        for (int k = l + 1; k <= r - 1; k++) {
            groups[k]++;
        }
        for (int k = r * len; k <= upper; k++) {
            if (buckets[k] > 0)
                buckets[k]--;
        }
    }
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    len = (int) ceil(n / sqrt(n));

    int buckets[n], groups[len];
    memset(groups, 0, sizeof(groups));

    for (int i = 0; i < n; i++)
        scanf("%d", &buckets[i]);

    int i, l, r;
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &i);
        i--;

        for(int k = (i/len) * len; k < min(n, (i/len + 1) * len); k++)
            buckets[k] = max(0, buckets[k] - groups[i/len]);

        groups[i/len] = 0;

        l = i - buckets[i];
        l = max(0, l);
        r = i + buckets[i];
        r = min(n-1, r);

        update(buckets, groups, l, r);
    }

    llong sum = 0;
    for (int k = 0; k < n; k++)
        sum += max(0, buckets[k] - groups[k/len]);

    printf("%lld\n", sum);
    return 0;
}