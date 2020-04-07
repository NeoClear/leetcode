#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode*, int> sums;
    int calc(TreeNode* node) {
        int val = 0;
        if (node->left)
            val += calc(node->left);
        if (node->right)
            val += calc(node->right);
        return sums[node] = val + node->val;
    }
    int maxProduct(TreeNode* root) {
        constexpr int mod = 1000000007;
        if (root == NULL) { return 0; }
        calc(root);
        long long ans = 0;
        long long total = sums[root];
        for (const auto& it : sums) {
            long long cur = it.second;
            ans = max(ans, (total - cur) * cur);
        }
        return ans % mod;
    }
};

int main() {
    Solution ins;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << ins.maxProduct(root);
    return 0;
}