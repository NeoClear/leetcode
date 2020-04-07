#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        vector<ListNode *> lst;
        auto p = head;
        while (p != NULL) {
            lst.push_back(p);
            p = p->next;
        }
        k %= lst.size();
        // 0 <= k < n
        if (k == 0)
            return head;
        lst.back()->next = head;
        lst[lst.size() - k - 1]->next = NULL;
        return lst[lst.size() - k];
    }
};

int main()
{
    return 0;
}
