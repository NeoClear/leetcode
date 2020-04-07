#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Actually simple
    string minRemoveToMakeValid(string s) {
        vector<int> v;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                v.push_back(i);
            else if (s[i] == ')') {
                if (v.empty())
                    s[i] = '*';
                else
                    v.pop_back();
            }
        }
        while (!v.empty()) {
            s[v.back()] = '*';
            v.pop_back();
        }
        // Learn remove function
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};

int main()
{
    return 0;
}
