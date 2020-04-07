#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string stack;
        for (const char& c : s) {
            if (c == ')') {
                if (stack.empty() || stack.back() != '(')
                    return false;
                stack.pop_back();
            } else if (c == ']') {
                if (stack.empty() || stack.back() != '[')
                    return false;
                stack.pop_back();
            } else if (c == '}') {
                if (stack.empty() || stack.back() != '{')
                    return false;
                stack.pop_back();
            } else
                stack.push_back(c);
        }
        return stack.empty();
    }
};

int main()
{
    return 0;
}
