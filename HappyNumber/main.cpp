#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int convert(int n) {
        int ans = 0;
        while (n) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (!visited.count(n)) {
            if (n == 1)
                return true;
            visited.insert(n);
            n = convert(n);
        }
        return false;
    }
};

int main()
{
    return 0;
}
