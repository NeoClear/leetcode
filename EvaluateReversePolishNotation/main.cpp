#include <bits/stdc++.h>

using namespace std;

namespace nmsl {
int divi(int x, int y) {
    return x / y;
}

int multi(int x, int y) {
    return x * y;
}

int plus(int x, int y) {
    return x + y;
}

int minus(int x, int y) {
    return x - y;
}
}



class Solution {
public:
    bool isNumber(string s) {
        if (s.front() == '-')
            s = s.substr(1);
        if (s.empty())
            return false;
        for (const auto& it : s)
            if (!isdigit(it))
                return false;
        return true;
    }
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for (const auto& it : tokens) {
            if (isNumber(it))
                stack.push_back(stoi(it));
            else {
                function<int(int, int)> f;
                if (it == "+")
                    f = nmsl::plus;
                else if (it == "-")
                    f = nmsl::minus;
                else if (it == "*")
                    f = nmsl::multi;
                else if (it == "/")
                    f = nmsl::divi;
                int y = stack.back();
                stack.pop_back();
                int x = stack.back();
                stack.pop_back();
                stack.push_back(f(x, y));
            }
        }
        return stack.front();
    }
};

int main()
{
    Solution ins;
    vector<string> in = {
        "10",
        "6",
        "9",
        "3",
        "+",
        "-11",
        "*",
        "/",
        "*",
        "17",
        "+",
        "5",
        "+"
    };
    cout<< ins.evalRPN(in)<< endl;
    return 0;
}
