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
    int length(TreeNode *root) {
        if (root == NULL) return 0;
        int l = length(root->left);
        int r = length(root->right);
        maxLen = max(maxLen, l + r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        length(root);
        return maxLen;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
