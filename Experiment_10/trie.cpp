#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    char data;
    vector<TrieNode*> child;
    bool end;

    TrieNode(char val) {
        data = val;
        child.resize(26, nullptr);
        end = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insert(const string& word) {
        TrieNode* temp = root;
        for (char c : word) {
            char lower = tolower(c);
            int ind = lower - 'a';
            if (ind < 0 || ind >= 26) {
                continue;
            }
            if (temp->child[ind] == nullptr) {
                temp->child[ind] = new TrieNode(lower);
            }
            temp = temp->child[ind];
        }
        temp->end = true;
    }

    bool search(const string& word) {
        TrieNode* temp = root;
        for (char c : word) {
            char lower = tolower(c);
            int ind = lower - 'a';
            if (ind < 0 || ind >= 26) {
                return false;
            }
            if (temp->child[ind] == nullptr) {
                return false;
            }
            temp = temp->child[ind];
        }
        return temp->end;
    }
};

int main() {
    Trie trie;
    trie.insert("ABCD");

    cout << (trie.search("abcd") ? "Found" : "Not Found") << '\n';
    cout << (trie.search("abce") ? "Found" : "Not Found") << '\n';

    return 0;
}
