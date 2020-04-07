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
    vector<int> depth;
    vector<string> ans_;
    string convert() {
        string ans;
        for (const auto& it : depth) {
            if (!ans.empty())
                ans += "->";
            ans += to_string(it);
        }
        return ans;
    }
    void solve(TreeNode *root) {
        depth.push_back(root->val);
        if (!root->left && !root->right)
            ans_.push_back(convert());
        if (root->left)
            solve(root->left);
        if (root->right)
            solve(root->right);
        depth.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)
            return {};
        solve(root);
        return ans_;
    }
};

int main()
{
    return 0;
}
