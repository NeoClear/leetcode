#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string& base = a.size() >= b.size() ? a : b;
        string& plus = a.size() >= b.size() ? b : a;
        for (auto itb = base.rbegin(), itp = plus.rbegin(); itp != plus.rend(); itb++, itp++) {
            (*itb) += (*itp - '0');
        }
        int up = 0;
        for (auto it = base.rbegin(); it != base.rend(); it++) {
            (*it) += up;
            up = (*it) > '1' ? 1 : 0;
            (*it) = (*it) > '1' ? (*it) - 2 : (*it);
        }
        if (up)
            base.insert(base.begin(), 1, '1');
        return base;
    }
};

int main()
{
    Solution ins;
    cout<< ins.addBinary("1010", "1011")<< endl;
    return 0;
}
