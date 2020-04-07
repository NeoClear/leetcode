#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *less = new ListNode(0);
        ListNode *greater = new ListNode(0);
        auto lp = less;
        auto gp = greater;
        auto p = head;
        while (p) {
            if (p->val < x) {
                lp->next = p;
                lp = lp->next;
            } else {
                gp->next = p;
                gp = gp->next;
            }
            p = p->next;
        }
        lp->next = greater->next;
        gp->next = NULL;
        return less->next;
    }
};

int main()
{
    return 0;
}
