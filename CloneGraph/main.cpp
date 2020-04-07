#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node *, Node*> map_;
    Node *solve(Node *node) {
        if (map_.count(node))
            return map_[node];
        Node *ret = new Node(node->val, {});
        map_[node] = ret;
        for (const auto& it : node->neighbors) {
            ret->neighbors.push_back(solve(it));
        }
        return ret;
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        return solve(node);
    }
};

int main()
{
    return 0;
}
