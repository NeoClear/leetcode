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
    vector<int> ans;
    void solve(TreeNode *root, int h) {
        if (ans.size() <= h) {
            ans.push_back(0);
            ans.back() = root->val;
        }
        if (root->right)
            solve(root->right, h + 1);
        if (root->left)
            solve(root->left, h + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};
        solve(root, 0);
        return ans;
    }
};

int main()
{
    return 0;
}
