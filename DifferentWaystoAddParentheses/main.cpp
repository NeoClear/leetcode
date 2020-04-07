#include <bits/stdc++.h>

using namespace std;

namespace nmsl {
int plus(int a, int b) {
    return a + b;
}
int minus(int a, int b) {
    return a - b;
}
int multi(int a, int b) {
    return a * b;
}
}

class Solution {
public:
    unordered_map<string, vector<int>> map_;
    const vector<int>& solve(string input) {
        if (map_.count(input)) return map_[input];
        vector<int> ans;
        for (int i = 0; i < input.size(); i++) {
            char op = input[i];
            if (op == '+' ||
                op == '-' ||
                op == '*') {
                string left = input.substr(0, i);
                string right = input.substr(i + 1);
                auto& lv = solve(left);
                auto& rv = solve(right);

                function<int(int, int)> f;
                switch (op) {
                case '+': f = nmsl::plus; break;
                case '-': f = nmsl::minus; break;
                case '*': f = nmsl::multi; break;
                }
                for (const auto& ll : lv)
                    for (const auto& rr : rv)
                        ans.push_back(f(ll, rr));
            }
        }
        if (ans.empty())
            ans.push_back(stoi(input));
        return map_[input] = ans;
    }
    vector<int> diffWaysToCompute(string input) {
        return solve(input);
    }
};

int main()
{
    return 0;
}
