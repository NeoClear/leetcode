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
    vector<int> ans_;
    void solve(TreeNode *root) {
        if (root->left == NULL) return;
        if (root->left->val < root->right->val) {
            solve(root->left);
            ans_.push_back(root->right->val);
        } else if (root->left->val > root->right->val) {
            solve(root->right);
            ans_.push_back(root->left->val);
        } else {
            solve(root->left);
            solve(root->right);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        solve(root);
        sort(ans_.begin(), ans_.end());
        return ans_.empty() ? -1 : ans_[0];
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
