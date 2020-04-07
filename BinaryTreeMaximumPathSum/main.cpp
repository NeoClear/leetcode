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
    int maxLength = INT_MIN;
    int length(TreeNode *root) {
        if (root == NULL) return 0;
        int left_ = max(0, length(root->left));
        int right_ = max(0, length(root->right));
        int sum = left_ + right_ + root->val;
        maxLength = max(maxLength, sum);
        return max(left_, right_) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        length(root);
        return maxLength;
    }
};

int main()
{
    return 0;
}
