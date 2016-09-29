/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: PHONELST - Phone List
 * Time limit per test: 0.532 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <string.h>
#include <iostream>

#define DEC_SIZE 10
// Converts key current character into index use only '0' through '9' and lower case
#define CHAR_TO_INDEX(c) ((int) c - (int) '0')

using namespace std;

bool isPrefixAnother = false;

struct TrieNode {
    struct TrieNode *children[DEC_SIZE];

    // isLeaf is true if the node represents end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *node = NULL;
    node = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (node) {
        int i;
        node->isLeaf = false;

        for (i = 0; i < DEC_SIZE; i++)
            node->children[i] = NULL;
    }
    return node;
}

// If not present, inserts key into trie, if the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, string key) {
    int index = 0;
    struct TrieNode *node = root;

    for (int i = 0; i < key.length(); i++) {
        index = CHAR_TO_INDEX(key[i]);

        if (node->isLeaf)
            isPrefixAnother = true;
        if (!node->children[index])
            node->children[index] = getNode();

        node = node->children[index];
    }
    for (TrieNode *child : node->children) {
        if (child) {
            isPrefixAnother = true;
            break;
        }
    }
    // mark last node as leaf
    node->isLeaf = true;
}

int main() {
    int t, n;
    string phone;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        struct TrieNode *root = getNode();

        for (int i = 0; i < n; i++) {
            cin >> phone;
            insert(root, phone);
        }
        if (isPrefixAnother) {
            printf("NO\n");
            isPrefixAnother = false;
        } else {
            printf("YES\n");
        }
    }
    return 0;
}