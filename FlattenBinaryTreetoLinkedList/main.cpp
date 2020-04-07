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
    TreeNode *ptr;
    void solve(TreeNode *root) {
        if (root == NULL)
            return;
        ptr->right = root;
        ptr = ptr->right;
        auto l = root->left;
        auto r = root->right;
        solve(l);
        solve(r);
        root->left = NULL;
    }
    void flatten(TreeNode* root) {
        ptr = new TreeNode(0);
        solve(root);
        ptr->right = NULL;
    }
};

int main()
{
    return 0;
}
