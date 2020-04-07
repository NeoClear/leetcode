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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        auto p = head;
        while (p) {
            if (visited.count(p))
                return p;
            visited.insert(p);
            p = p->next;
        }
        return NULL;
    }
};

int main()
{
    return 0;
}
