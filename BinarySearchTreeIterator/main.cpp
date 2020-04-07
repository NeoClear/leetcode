#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    vector<TreeNode *> stack;
    BSTIterator(TreeNode* root) {
        while (root) {
            stack.push_back(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        auto ptr = stack.back();
        stack.pop_back();
        if (ptr->right) {
            auto p = ptr->right;
            while (p) {
                stack.push_back(p);
                p = p->left;
            }
        }
        return ptr->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty();
    }
};

int main()
{
    return 0;
}
