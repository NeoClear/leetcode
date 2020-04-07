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
    bool ans_ = true;
    int height(TreeNode *root) {
        if (root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        ans_ &= abs(left - right) <= 1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return ans_;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
