#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    unordered_set<ListNode *> visited;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while (headA) {
            visited.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (visited.count(headB))
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};

int main()
{
    return 0;
}
