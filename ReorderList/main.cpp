#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int count(ListNode *root) {
        int ans = 0;
        while (root) {
            ans++;
            root = root->next;
        }
        return ans;
    }
    void reorderList(ListNode* head) {
        int cnt = count(head);
        if (cnt <= 2)
            return;
        auto p = head;
        auto q = head;
        for (int i = 0; i < (cnt + 1) / 2; i++, q = q->next) {}
        ListNode *pre = NULL;
        while (q) {
            auto dest = q->next;
            q->next = pre;
            pre = q;
            q = dest;
        }
        auto ret = new ListNode(0);
        for (int i = 0; i < cnt; i++) {
            if (i % 2 == 0) {
                ret->next = p;
                p = p->next;
            } else {
                ret->next = pre;
                pre = pre->next;
            }
            ret = ret->next;
        }
        ret->next = NULL;
    }
};

int main()
{

    return 0;
}
