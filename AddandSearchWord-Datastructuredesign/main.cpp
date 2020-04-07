#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
    bool isWord;
    vector<TrieNode *> child;
    TrieNode()
        : isWord(false),
          child(26, NULL) {}
};

class WordDictionary {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto ptr = root;
        for (const auto& c : word) {
            if (!ptr->child[c - 'a'])
                ptr->child[c - 'a'] = new TrieNode();
            ptr = ptr->child[c - 'a'];
        }
        ptr->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool solve(string word, TrieNode *head) {
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (int k = 0; k < 26; k++) {
                    if (head->child[k] && solve(word.substr(i + 1), head->child[k]))
                        return true;
                }
                return false;
            }
            if (head->child[c - 'a'] == NULL)
                return false;
            head = head->child[c - 'a'];
        }
        return head->isWord;
    }
    bool search(string word) {
        return solve(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main()
{
    return 0;
}
