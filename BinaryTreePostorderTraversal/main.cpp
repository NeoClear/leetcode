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
        if (root == NULL) return;
        solve(root->left);
        solve(root->right);
        ans_.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        solve(root);
        return ans_;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
