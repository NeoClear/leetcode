#include <bits/stdc++.h>

using namespace std;

class MapSum {
public:
    class TrieNode {
    public:
        int val;
        vector<TrieNode *> child;
        TrieNode():
            val(0),
            child(26, nullptr) {}
        ~TrieNode() { for (const auto& c : child) if (c) delete c; child.clear(); }
    };
    /** Initialize your data structure here. */
    unique_ptr<TrieNode> root_;
    MapSum(): root_(new TrieNode) {}

    void insert(string key, int val) {
        TrieNode *p = root_.get();
        for (const auto& c : key) {
            if (!p->child[c - 'a']) p->child[c - 'a'] = new TrieNode;
            p = p->child[c - 'a'];
        }
        p->val = val;
    }
    TrieNode *find(string word) {
        TrieNode *p = root_.get();
        for (const auto& c : word) {
            p = p->child[c - 'a'];
            if (p == NULL) break;
        }
        return p;
    }
    int count(TrieNode *root) {
        int ans = root->val;
        for (const auto& c : root->child)
            if (c) ans += count(c);
        return ans;
    }
    int sum(string prefix) {
        TrieNode *ret = find(prefix);
        return ret == NULL ? 0 : count(ret);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
