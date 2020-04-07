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
    TreeNode* sortedArrayToBST(vector<int> nums) {
        if (nums.empty())
            return NULL;
        int mid = nums.size() / 2;
        auto root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(vector<int>(nums.begin(),nums.begin() + mid));
        root->right = sortedArrayToBST(vector<int>(nums.begin() + mid + 1, nums.end()));
        return root;
    }
};

int main()
{
    return 0;
}
