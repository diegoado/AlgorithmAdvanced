/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1284 - Cellphone Typing
 * Time limit per test: 3 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define ALF 26
// Converts key current character into index use only 'a' through 'z' and lower case
#define CHAR_TO_INT(c) ((int) c - (int) 'a')

using namespace std;

struct Trie {
    int keys;
    Trie *children[ALF];

    Trie() {
        keys = 0;
        for (int i = 0; i < ALF; i++)
            children[i] = NULL;
    }

    ~Trie() {
        for (int i = 0; i < ALF; i++)
            delete children[i];
    }

    void insert(const char *s) {
        if (*s == '\0')
            return;

        int i = CHAR_TO_INT(*s);
        Trie *node = children[i];

        if (!children[i]) {
            node = children[i] = new Trie();
            node->keys = 1;
        } else {
            node->keys++;
        }
        node->insert(s + 1);
    }

    int countKeys(const char *s, int k = 0) {
        if(*s == '\0')
            return k;

        Trie *tree = children[CHAR_TO_INT(*s)];
        if (tree == NULL)
            return 0;

        return tree->countKeys(s + 1, keys == tree->keys ? k : k + 1);
    }
};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        string dict[n];
        struct Trie *tree = new Trie();

        for (int i = 0; i < n; i++) {
            cin >> dict[i];
            tree->insert(dict[i].c_str());
        }
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += tree->countKeys(dict[i].c_str());
        }
        printf("%.2lf\n", sum / n);
    }
    return 0;
}
