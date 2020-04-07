#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool is_even(int n) {
        int cnt = 0;
        for (; n; n /= 10, cnt++) {}
        return cnt % 2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (const auto& it : nums) {
            if (is_even(it)) { cnt++; }
        }
        return cnt;
    }
};

int main() {
    return 0;
}