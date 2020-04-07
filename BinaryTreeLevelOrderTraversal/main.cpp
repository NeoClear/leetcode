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
    void solve(TreeNode *root, int level) {
        if (root == NULL) return;
        if (level > ans_.size())
            ans_.push_back(vector<int>(0));
        ans_[level - 1].push_back(root->val);
        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        solve(root, 1);
        return ans_;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
