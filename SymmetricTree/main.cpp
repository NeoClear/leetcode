#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool sameTree(TreeNode *l, TreeNode *r) {
        if (l == NULL)
            return r == NULL;
        if (r == NULL)
            return l == NULL;
        return l->val == r->val &&
                sameTree(l->left, r->right) &&
                sameTree(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return sameTree(root->left, root->right);
    }
};

int main()
{
    return 0;
}
