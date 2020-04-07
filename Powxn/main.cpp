#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<long long, double>> dis;
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        bool f = n < 0 ? false : true;
        long long nn = abs((long long)n);
        dis.push_back({1, x});
        for (long long i = 2; i <= nn; i *= 2) {
            dis.push_back({i, dis.back().second * dis.back().second});
        }
        for (const auto& it : dis)
            cout<< it.first<< ": "<< it.second<< endl;
        double ans = 1;
        for (auto it = dis.rbegin(); it != dis.rend() && nn != 0; it++) {
            if (it->first <= nn) {
                nn -= it->first;
                ans *= it->second;
            }
        }
        return f ? ans : 1 / ans;
    }
};

int main()
{
    Solution ins;
    cout<< ins.myPow(2, 10)<< endl;
    return 0;
}
