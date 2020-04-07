#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return {0};
        else if (n == 1)
            return {0, 1};
        vector<int> ans;
        auto ret = grayCode(n - 1);
        for (auto it = ret.begin(); it != ret.end(); it++)
            ans.push_back((*it) << 1);
        for (auto it = ret.rbegin(); it != ret.rend(); it++)
            ans.push_back(((*it) << 1) + 1);
        return ans;
    }
};

int main()
{
    return 0;
}
