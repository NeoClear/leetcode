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
    int prev_ = INT_MIN;
    vector<int> vec_;
    void solve(TreeNode *root) {
        if (root == NULL)
            return;
        solve(root->left);
        vec_.push_back(root->val);
        solve(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL)
            return true;
        solve(root);
        for (int i = 1; i < vec_.size(); i++)
            if (vec_[i - 1] >= vec_[i])
                return false;
        return true;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
