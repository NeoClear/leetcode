#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        set<int> keys;
        for (const auto& it : nums) { count[it]++; }
        for (const auto& it : nums) { keys.insert(it); }
        for (const auto& it : keys) {
            if (count[it] == 0) { continue; }
            int minus = count[it];
            for (int i = it; i < it + k; i++) {
                if (count[i] < minus) { return false; }
                count[i] -= minus;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}