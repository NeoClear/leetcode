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
    vector<vector<int>> cache_;
    void solve(TreeNode *root, int level) {
        if (root == NULL) return;
        if (level > cache_.size())
            cache_.push_back({});
        cache_[level - 1].push_back(root->val);
        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        solve(root, 1);
        vector<double> ans_;
        for (const auto& level : cache_) {
            int div = level.size();
            int64_t acc = 0;
            for (const auto& ele : level)
                acc += ele;
            ans_.push_back(static_cast<double>(acc) / div);
        }
        return ans_;
    }
};

int main()
{
    return 0;
}
