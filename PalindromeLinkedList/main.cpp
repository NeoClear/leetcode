#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> storage;
        while (head) {
            storage.push_back(head->val);
            head = head->next;
        }
        return storage == vector<int>(storage.rbegin(), storage.rend());
    }
};

int main()
{
    return 0;
}
