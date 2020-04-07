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
    unordered_map<TreeNode *, int> dp;
    int depth(TreeNode *root) {
        if (root == NULL) return dp[root] = 0;
        return dp[root] = max(depth(root->left), depth(root->right)) + 1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root);
        cout<< dp[root->left]<< dp[root->right]<< endl;
        if (dp[root->left] == dp[root->right]) return root;
        else if (dp[root->left] > dp[root->right]) return subtreeWithAllDeepest(root->left);
        else return subtreeWithAllDeepest(root->right);
    }
};

int main()
{
    return 0;
}
