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
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
        vector<Node *> vect;
        vect.push_back(root);
        while (!vect.empty()) {
            for (int i = 0; i < vect.size() - 1; i++)
                vect[i]->next = vect[i + 1];
            vect.back()->next = NULL;
            vector<Node *> temp;
            for (const auto& it : vect) {
                if (it->left)
                    temp.push_back(it->left);
                if (it->right)
                    temp.push_back(it->right);
            }
            vect.clear();
            vect.swap(temp);
        }
        return root;
    }
};

int main()
{
    return 0;
}
