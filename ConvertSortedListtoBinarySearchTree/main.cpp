#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> nums;
    void gen(ListNode *ptr) {
        while (ptr) {
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }
    }
    TreeNode *solve(vector<int> num) {
        if (num.empty())
            return NULL;
        int mid = num.size() / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = solve(vector<int>(num.begin(), num.begin() + mid));
        root->right = solve(vector<int>(num.begin() + mid + 1, num.end()));
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        gen(head);
        return solve(nums);
    }
};

int main()
{
    return 0;
}
