#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int cnt = 0;
        unordered_set<int> visited(arr.begin(), arr.end());
        for (const auto& it : arr)
            if (it == 0) { cnt++; }
        if (cnt >= 2) { return true; }
        for (const auto& it : arr)
            if (visited.count(it * 2) && it != 0)
                return true;
        return false;
    }
};

int main() {
    Solution ins;
    vector<int> in = {
        3,1,7,11
    };
    if (ins.checkIfExist(in))
        cout << "True" << endl;
    return 0;
}

