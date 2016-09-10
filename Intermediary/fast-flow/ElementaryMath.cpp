/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Open Kattis
 * Problem: Elementary Math
 * Time limit per test: 23 seconds
 * Memory limit per test: 1024 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <map>
#include <vector>
#include <cstring>

#define MAX_N 2500
#define MAX_V 4 * MAX_N

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int match[MAX_V];
bool seen[MAX_V];

vector<pll> arr;
vector<int> graph[MAX_V];

map<ll, int> results;

bool bpm(int u) {
    if (seen[u]) {
        return false;
    }
    seen[u] = true;
    for (int v : graph[u]) {
        if (match[v] == -1 || bpm(match[v])){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);

    ll a, b;
    ll add, sub, mul;
    int count = MAX_N;
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &a, &b);
        add = a + b, sub = a - b, mul = a * b;

        if (!results.count(add))
            results[add] = count++;
        if (!results.count(sub))
            results[sub] = count++;
        if (!results.count(mul))
            results[mul] = count++;

        graph[i].push_back(results[add]);
        graph[i].push_back(results[sub]);
        graph[i].push_back(results[mul]);
        graph[results[add]].push_back(i);
        graph[results[sub]].push_back(i);
        graph[results[mul]].push_back(i);

        arr.push_back({a, b});
    }
    int answers = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < n; i++) {
        memset(seen, 0, sizeof(seen));
        answers += bpm(i);
    }
    if (answers != n) {
        printf("impossible\n");
    } else {
        for (int i = 0; i < n; ++i) {
            a = arr[i].first, b = arr[i].second;
            if (match[i] == results[a + b])
                printf("%lld + %lld = %lld\n", a, b, a + b);
            else if (match[i] == results[a - b])
                printf("%lld - %lld = %lld\n", a, b, a - b);
            else
                printf("%lld * %lld = %lld\n", a, b, a * b);
        }
    }
    return 0;
}