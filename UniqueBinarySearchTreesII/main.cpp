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
    unordered_map<long long, vector<TreeNode *>> map_;
    long long tag(int x, int y) {
        return (static_cast<long long>(x) << 32) + static_cast<long long>(y);
    }
    vector<TreeNode *> solve(int l, int r) {
        if (map_.count(tag(l, r)))
            return map_[tag(l, r)];
        if (l == r)
            return {new TreeNode(l)};
        if (l > r)
            return {NULL};
        vector<TreeNode *> ans;
        for (int i = l; i <= r; i++) {
            auto left = solve(l, i - 1);
            auto right = solve(i + 1, r);
            for (const auto& ll : left)
                for (const auto& rr : right) {
                    ans.push_back(new TreeNode(i));
                    ans.back()->left = ll;
                    ans.back()->right = rr;
                }
        }
        return map_[tag(l, r)] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return solve(1, n);
    }
};

int main()
{
    return 0;
}
