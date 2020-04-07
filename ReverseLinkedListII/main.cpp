#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL)
            return NULL;
        ListNode *cur = head;
        ListNode *pre = NULL;
        while (m > 1) {
            pre = cur;
            cur = cur->next;
            m--;
            n--;
        }
        auto fix_pre = pre;
        auto tt = cur;
        while (n) {
            auto real_next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = real_next;
            n--;
        }
        if (fix_pre)
            fix_pre->next = pre;
        else
            head = pre;
        tt->next = cur;
        return head;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
