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

    vector<TreeNode *> ans;
    TreeNode *leftmost(TreeNode *root) {
        auto p = root->left;
        while (p->right)
            p = p->right;
        return p;
    }
    TreeNode *rightmost(TreeNode *root) {
        auto p = root->right;
        while (p->left)
            p = p->left;
        return p;
    }
    void solve(TreeNode *root) {
        if (root == NULL)
            return;
        if (root->left)
            solve(root->left);
        if (root->left && leftmost(root)->val > root->val) {
            ans.push_back(leftmost(root));
            ans.push_back(root);
        }
        if (root->right && rightmost(root)->val < root->val) {
            if (ans.back() != root)
                ans.push_back(root);
            ans.push_back(rightmost(root));
        }
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        auto pat = vector<TreeNode *>(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            ans[i]->val = pat[i]->val;
    }
};

int main()
{
    return 0;
}
