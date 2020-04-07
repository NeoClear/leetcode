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
    vector<vector<int>> ans;
    void solve(TreeNode *root, int h) {
        if (root == NULL)
            return;
        if (h >= ans.size())
            ans.push_back({});
        ans[h].push_back(root->val);
        solve(root->left, h + 1);
        solve(root->right, h + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solve(root, 0);
        for (int i = 0; i < ans.size(); i++) {
            if (i & 1 == 1)
                reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

int main()
{
    return 0;
}
