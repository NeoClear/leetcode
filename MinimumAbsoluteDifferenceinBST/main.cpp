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
    vector<int> vec_;
    int delta_ = INT_MAX;
    int prev_ = -1;
    void solve(TreeNode *root) {
        if (root == NULL)
            return;
        solve(root->left);
        if (prev_ != -1) {
            delta_ = min(delta_, root->val - prev_);
        }
        prev_ = root->val;
        cout<< root->val;
        solve(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return delta_;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
