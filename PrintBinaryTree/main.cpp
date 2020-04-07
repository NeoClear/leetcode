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
    int height(TreeNode *root) {
        if (root == NULL) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    int H_;
    int W_;
    vector<vector<string>> ans_;
    int dis(int x) {
        return pow(2, H_ - x - 2);
    }
    void solve(TreeNode *root, int x, int y) {
        if (root == NULL) return;
        ans_[x][y] = to_string(root->val);
        solve(root->left, x + 1, y - dis(x));
        solve(root->right, x + 1, y + dis(x));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        H_ = height(root);
        W_ = (pow(2, (H_ - 1)) - 1) * 2 + 1;
        ans_ = vector<vector<string>>(H_, vector<string>(W_));
        solve(root, 0, W_ / 2);
        return ans_;
    }
};

int main()
{
    Solution ins;
    TreeNode *in = new TreeNode(1);
    in->left = new TreeNode(2);
    in->left->left = new TreeNode(3);
    in->left->left->left = new TreeNode(4);
    in->right = new TreeNode(5);
    for (const auto& line : ins.printTree(in)) {
        for (const auto& c : line) {
            cout<< c<< " ";
        }
        cout<< endl;
    }
    return 0;
}
