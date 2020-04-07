#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> cache;
    int tag(int a, int b) { return (a << 16) | b; }
    int solve(string& s, int l, int r) {
        if (l >= r)
            return 0;
        if (cache.count(tag(l, r)))
            return cache[tag(l, r)];
        if (s[l] == s[r])
            return cache[tag(l, r)] = solve(s, l + 1, r - 1);
        return cache[tag(l, r)] = min(solve(s, l, r - 1),
                                      solve(s, l + 1, r)) + 1;
        
    }
    int minInsertions(string s) {
        return solve(s, 0, s.length() - 1);
    }
};

int main() {
    Solution ins;
    cout << ins.minInsertions("leetcode") << endl;
    return 0;
}