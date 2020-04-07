#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    vector<Node *> stack;
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
        stack.push_back(root);
        while (!stack.empty()) {
            for (int i = 0; i < stack.size() - 1; i++)
                stack[i]->next = stack[i + 1];
            stack.back()->next = NULL;
            vector<Node *> temp;
            for (const auto& it : stack) {
                if (!it->left && !it->right)
                    break;
                temp.push_back(it->left);
                temp.push_back(it->right);
            }
            stack.swap(temp);
        }
        return root;
    }
};

int main()
{
    return 0;
}
