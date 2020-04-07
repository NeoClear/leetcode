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
    void build(TreeNode *root, int h) {
        if (root == NULL)
            return;
        if (ans.size() <= h)
            ans.push_back({});
        ans[h].push_back(root->val);
        build(root->left, h + 1);
        build(root->right, h + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        build(root, 0);
        return vector<vector<int>>(ans.rbegin(), ans.rend());
    }
};

int main()
{
    return 0;
}
