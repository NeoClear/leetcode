#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int K;
    ListNode* solve(ListNode *root) {
        ListNode *p = root;
        vector<ListNode *> table;
        int i;
        for (i = 0; i < K && p != NULL; i++) {
            table.push_back(p);
            p = p->next;
        }
        if (p == NULL && i != K)
            return root;
        for (int i = K - 1; i > 0; i--) {
            table[i]->next = table[i - 1];
        }

        ListNode *pp = table.back();
//        while (pp) {
//            cout<< pp->val<< " sd"<< endl;
//            pp = pp->next;
//        }

        ListNode *t = table.back();
        table[0]->next = solve(p);
        return t;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == NULL || head->next == NULL) return head;
        K = k;
        return solve(head);
    }
};

int main()
{
    auto l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
//    l1->next->next->next->next = new ListNode(5);
    Solution ins;
    auto p = ins.reverseKGroup(l1, 2);
    while (p) {
        cout<< p->val<< endl;
        p = p->next;
    }
    return 0;
}
