#include <bits/stdc++.h>

using namespace std;

class Trie {
    class TrieNode {
    public:
        bool is_word;
        vector<TrieNode *> child;
        TrieNode():
            is_word(false),
            child(26, nullptr) {}
        ~TrieNode() {
            for (TrieNode *c : child)
                if (c) delete c;
        }
    };

public:
    unique_ptr<TrieNode> root_;
    /** Initialize your data structure here. */
    Trie(): root_(new TrieNode) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root_.get();
        for (const auto& c : word) {
            if (!p->child[c - 'a'])
                p->child[c - 'a'] = new TrieNode;
            p = p->child[c - 'a'];
        }
        p->is_word = true;
    }
    TrieNode *find(string word) {
        TrieNode *p = root_.get();
        for (const auto& c : word) {
            p = p->child[c - 'a'];
            if (!p)
                break;
        }
        return p;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *ret = find(word);
        return ret != NULL && ret->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
