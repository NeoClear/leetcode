#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, int> map_;
    int numDecodings(string s) {
        if (s.size() == 0)
            return 1;
        if (s.front() == '0')
            return 0;
        if (s.size() == 1)
            return 1;
        if (map_.count(s))
            return map_[s];
        char cur = s.front();
        char next = *(s.begin() + 1);
        int v = (cur - '0') * 10 + (next - '0');
//        cout<< cur<< ", "<< next<< endl;
        if (v == 10 || v == 20)
            return map_[s] = numDecodings(s.substr(2));
        if (v <= 26) {
            return map_[s] = numDecodings(s.substr(1)) + numDecodings(s.substr(2));
        }
        return map_[s] = numDecodings(s.substr(1));
    }
};

int main()
{
    Solution ins;
    cout<< ins.numDecodings("10")<< endl;
    return 0;
}
