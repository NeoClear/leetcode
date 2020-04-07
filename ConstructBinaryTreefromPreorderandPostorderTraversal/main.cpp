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
    vector<int> *pre_, *post_;
    int indexOf(vector<int>& v, int start, int val) {
        int N = v.size();
        for (int i = start; i < N; i++)
            if (v[i] == val) return i;
        return -1;
    }
    TreeNode *solve(int prel, int postl, int size) {
        if (size <= 0) return NULL;
        if (size == 1) return new TreeNode((*pre_)[prel]);
        TreeNode *root = new TreeNode((*pre_)[prel]);
        int left_most = (*pre_)[prel + 1];
        int size_l = indexOf(*post_, postl, left_most) - postl + 1;
        int size_r = size - 1 - size_l;
        root->left = solve(prel + 1, postl, size_l);
        root->right = solve(prel + 1 + size_l, postl + size_l, size_r);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        pre_ = &pre;
        post_ = &post;
        return solve(0, 0, pre.size());
    }
};

int main()
{
    return 0;
}
