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
    vector<vector<int>> ans_;
    int sum_;
    vector<int> path;
    void solve(TreeNode *root) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (accumulate(path.begin(), path.end(), 0) == sum_)
                ans_.push_back(path);
            path.pop_back();
            return;
        }
        if (root->left)
            solve(root->left);
        if (root->right)
            solve(root->right);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return {};
        sum_ = sum;
        solve(root);
        return ans_;
    }
};

int main()
{
    return 0;
}
