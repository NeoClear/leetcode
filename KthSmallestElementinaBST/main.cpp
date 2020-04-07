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
    TreeNode *ans = NULL;
    int K;
    int solve(TreeNode *root) {
        if (ans)
            return 0;
        if (root == NULL)
            return 0;
        int left = solve(root->left);
        if (ans)
            return 0;
        if (K == 0) {
            ans = root;
            return 0;
        }
        K--;
        int right = solve(root->right);
        if (ans)
            return 0;
        return left + right + 1;
    }
    int kthSmallest(TreeNode* root, int k) {
        K = k - 1;
        solve(root);
        return ans->val;
    }
};

int main()
{
    return 0;
}
