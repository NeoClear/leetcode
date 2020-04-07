#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    unordered_set<int> desu;
    int ans = 0;
    ListNode *group(ListNode *tar) {
        ans++;
        while (tar && desu.count(tar->val)) tar = tar->next;
        return tar;
    }
    int numComponents(ListNode* head, vector<int>& G) {
        desu = unordered_set<int>(G.begin(), G.end());
        ListNode *it = head;
        while (it) {
            if (desu.count(it->val)) it = group(it);
            else it = it->next;
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    ListNode *in = new ListNode(0);
    in->next = new ListNode(1);
    in->next->next = new ListNode(2);
    in->next->next->next = new ListNode(3);
    vector<int> G = {0, 1, 3};

    cout<< ins.numComponents(in, G);
    return 0;
}
