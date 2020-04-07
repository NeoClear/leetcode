#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ss, tt;
        for (const auto& c : s)
            ss[c]++;
        for (const auto& c : t)
            tt[c]++;
        for (const auto& it : ss)
            if (it.second != tt[it.first])
                return false;
        for (const auto& it : tt)
            if (it.second != ss[it.first])
                return false;
        return true;
    }
};

int main()
{
    return 0;
}
