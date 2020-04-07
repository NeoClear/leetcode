#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool solve(int n) {
        while (n > 0) {
            if (n % 10 == 0)
                return false;
            n /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (solve(i) && solve(n - i))
                return {i, n - i};
        }
        return {};
    }
};

int main() {
    Solution ins;
    for (const auto& it : ins.getNoZeroIntegers(1010))
        cout << it << endl; 
    return 0;
}