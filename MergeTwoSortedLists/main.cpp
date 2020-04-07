#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(0);
        ListNode *q = ret;
        while (l1 || l2) {
            int left = l1 ? l1->val : INT_MAX;
            int right = l2 ? l2->val : INT_MAX;
            if (left < right) {
                q->next = l1;
                l1 = l1->next;
            } else {
                q->next = l2;
                l2 = l2->next;
            }
            q = q->next;
        }
        return ret->next;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
