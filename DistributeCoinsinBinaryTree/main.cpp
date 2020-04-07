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
    int ans = 0;
    int balance(TreeNode *node) {
        if (!node) return 0;
        int lef = balance(node->left);
        int rig = balance(node->right);
        ans += abs(lef) + abs(rig);
        return 1 - node->val + lef + rig;
    }
    int distributeCoins(TreeNode* root) {
        balance(root);
        return ans;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
