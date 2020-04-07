#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getN(set<int>& set_, int n) {
        int i = 0;
        for (auto it = set_.begin(); it != set_.end(); it++, i++) {
            if (i == n)
                return *it;
        }
        return 0;
    }
    string getPermutation(int n, int k) {
        if (n == 1)
            return "1";
        vector<int> div = {1};
        for (int i = 2; i < n; i++)
            div.push_back(div.back() * i);
        set<int> set_;
        for (int i = 1; i <= n; i++)
            set_.insert(i);
        vector<int> ans;
        for (auto it = div.rbegin(); it != div.rend(); it++) {
            int rank = (k - 1) / *it;
            int num = getN(set_, rank);
            set_.erase(num);
            ans.push_back(num);
            k -= rank * (*it);
        }
        ans.push_back(*set_.begin());
        string ret;
        for (const auto& it : ans)
            ret.push_back('0' + it);
        return ret;
    }
};

int main()
{
    Solution ins;
    cout<< ins.getPermutation(4, 9);
    return 0;
}
