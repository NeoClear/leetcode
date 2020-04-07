#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        auto solve = [&]() {
            bool carry = true;
            for (auto it = s.rbegin(); it != s.rend() && carry; it++) {
                carry = false;
                (*it)++;
                if (*it == '2') {
                    *it = '0';
                    carry = true;
                }
            }
        };
        while (s.find('0') != s.npos) {
            if (s.back() == '0')
                s.pop_back();
            else
                solve();
            steps++;
        }
        return steps + (s == "1" ? 0 : s.length() + 1);
    }
};

int main() {
    return 0;
}

