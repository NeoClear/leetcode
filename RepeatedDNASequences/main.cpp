#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int acgt(char c) {
        switch (c) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        }
        return -1;
    }
    char tgca(int val) {
        switch (val) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        }
        return '@';
    }
    unordered_set<int> visited;
    unordered_set<int> ans;
    int insert(int val, char c) {
        return ((val << 2) + acgt(c)) & 0xfffff;
    }
    string int2str(int val) {
        string ret;
        for (int i = 0; i < 10; i++) {
            ret = tgca(val & 0x3) + ret;
            val >>= 2;
        }
        return ret;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        int cur = 0;
        for (int i = 0; i < 9; i++)
            cur = insert(cur, s[i]);
        for (int i = 9; i < s.size(); i++) {
            cur = insert(cur, s[i]);
            if (visited.count(cur))
                ans.insert(cur);
            visited.insert(cur);
        }
        vector<string> ret;
        for (const auto& it : ans)
            ret.push_back(int2str(it));
        return ret;
    }
};

int main()
{
    return 0;
}
