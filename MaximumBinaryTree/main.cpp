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
    int N;
    vector<int> nums_;
    TreeNode *solve(int l, int r) {
        if (l > r) return NULL;
        int index = l;
        for (int i = l; i <= r; i++) {
            if (nums_[i] > nums_[index])
                index = i;
        }
        TreeNode *ret = new TreeNode(nums_[index]);
        ret->left = solve(l, index - 1);
        ret->right = solve(index + 1, r);
        return ret;
    }
    TreeNode* constructMaximumBinaryTree(vector<int> nums) {
        N = nums.size();
        nums_.swap(nums);
        return solve(0, N - 1);
    }
};

void print(TreeNode *root) {
    if (root == NULL) return;
    print(root->left);
    cout<< root->val<< " ";
    print(root->right);
}

int main()
{
    Solution ins;
    print(ins.constructMaximumBinaryTree({3, 2, 1, 6, 0, 5}));
    return 0;
}
