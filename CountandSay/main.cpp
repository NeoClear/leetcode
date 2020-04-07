#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ret = countAndSay(n - 1);
        ret.push_back('@');
        int count = 1;
        string ans;
        for (int i = 0; i < ret.size() - 1; i++) {
            if (ret[i] != ret[i + 1]) {
                ans += to_string(count) + ret[i];
                count = 1;
            } else
                count++;
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    cout<< ins.countAndSay(5)<< endl;
    return 0;
}
