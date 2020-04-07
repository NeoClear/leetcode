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
    int l, r;
    TreeNode *solve(TreeNode *root) {
        if (root == NULL) return NULL;
        if (root->val < l)
            return solve(root->right);
        if (root->val > r)
            return solve(root->left);
        root->left = solve(root->left);
        root->right = solve(root->right);
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        l = L;
        r = R;
        return solve(root);
    }
};

int main()
{
    return 0;
}
