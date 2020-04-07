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
    int solve(TreeNode *root, bool left) {
        if (root == NULL) return 0;
        if (!root->left && !root->right) {
            return left ? root->val : 0;
        }
        return solve(root->left, true) +
               solve(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false);
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
