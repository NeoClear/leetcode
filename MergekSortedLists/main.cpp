#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        if (lists.size() == 1) return lists[0];
        vector<int> ans;
        for (auto it : lists) {
            while (it != NULL) {
                ans.push_back(it->val);
                it = it->next;
            }
        }
        sort(ans.begin(), ans.end());
        int N = ans.size();
        if (ans.empty()) return NULL;
        ListNode *root = new ListNode(ans[0]);
        ListNode *q = root;
        for (int i = 1; i < N; i++) {
            q->next = new ListNode(ans[i]);
            q = q->next;
        }
        return root;
    }
};

int main()
{
    Solution ins;
    return 0;
}
