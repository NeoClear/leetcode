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
    int maxLen = 0;
    pair<int, int> length(TreeNode *root) {
        if (root == NULL) return {0, 0};
        auto left = length(root->left);
        auto right = length(root->right);
        int l_ = left.second == root->val ? left.first : 0;
        int r_ = right.second == root->val ? right.first : 0;
        maxLen = max(maxLen, l_ + r_);
        return {max(l_, r_) + 1, root->val};
    }
    int longestUnivaluePath(TreeNode* root) {
        length(root);
        return maxLen;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
