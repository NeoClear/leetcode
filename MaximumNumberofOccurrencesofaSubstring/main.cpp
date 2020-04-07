#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> occur;
        for (int i = 0; i < s.length() - minSize + 1; i++) {
            string w = s.substr(i, minSize);
            unordered_set<char> cnt(w.begin(), w.end());
            if (cnt.size() <= maxLetters) { occur[s.substr(i, minSize)]++; }
        }
        int ans = 0;
        for (const auto& kv : occur) {
            ans = max(ans, kv.second);
        }
        return ans;
    }
};

int main() {
    return 0;
}