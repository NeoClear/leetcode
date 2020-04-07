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
    vector<vector<int>> graph;
    void dfs(TreeNode *par, TreeNode *cur) {
        if (par) {
            graph[par->val].push_back(cur->val);
            graph[cur->val].push_back(par->val);
        }
        if (cur->left) dfs(cur, cur->left);
        if (cur->right) dfs(cur, cur->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans = vector<int>(0);
        graph = vector<vector<int>>(501);
        dfs(NULL, root);
        queue<int> q;
        q.push(target->val);
        unordered_set<int> seen;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front(); q.pop();
                if (seen.count(node))
                    continue;
                seen.insert(node);
                if (!K)
                    ans.push_back(node);
                for (int i = 0; i < graph[node].size(); i++) q.push(graph[node][i]);
            }
            K--;
        }
        return ans;
    }
};

int main()
{
    return 0;
}
