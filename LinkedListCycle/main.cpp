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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        auto p = head;
        while (p) {
            if (visited.count(p))
                return true;
            visited.insert(p);
            p = p->next;
        }
        return false;
    }
};

int main()
{
    return 0;
}
