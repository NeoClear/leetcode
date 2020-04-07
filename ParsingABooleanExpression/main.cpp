#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string expr;
    int ptr = 0;
    void read_comma() {
        if (expr[ptr] == ',')
            ptr++;
    }
    void read_lparen() {
        if (expr[ptr] == '(')
            ptr++;
    }
    void read_rparen() {
        if (expr[ptr] == ')')
            ptr++;
    }
    bool eval() {
        char cur = expr[ptr];
        bool ans;
        switch (cur) {
        case 't':
            ptr++;
            return true;
        case 'f':
            ptr++;
            return false;
        case '!':
            ptr++;
            read_lparen();
            ans = eval();
            read_rparen();
            return !ans;
        case '&':
            ptr++;
            read_lparen();
            ans = eval();
            while (expr[ptr] != ')') {
                read_comma();
                ans &= eval();
            }
            read_rparen();
            return ans;
        case '|':
            ptr++;
            read_lparen();
            ans = eval();
            while (expr[ptr] != ')') {
                read_comma();
                ans |= eval();
            }
            read_rparen();
            return ans;
        }
        return false;
    }
    bool parseBoolExpr(string expression) {
        expr.swap(expression);
        return eval();
    }
};

int main()
{
    Solution ins;
    if (ins.parseBoolExpr("|(f,t)"))
        cout<< "YES"<< endl;
    else
        cout<< "NO"<< endl;
    return 0;
}
