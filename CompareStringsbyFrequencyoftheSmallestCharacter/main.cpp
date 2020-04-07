#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> query;
    vector<int> word;
    vector<int> ans;
    int count(string s) {
        char compare = 'z';
        int cnt = 0;
        for (const auto& c : s) {
            if (c < compare) {
                compare = c;
                cnt = 1;
            } else if (c == compare)
                cnt++;
        }
        return cnt;
    }
    vector<int> convert(vector<string> array) {
        vector<int> ret;
        for (const auto& it : array)
            ret.push_back(count(it));
        return ret;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        query = convert(queries);
        word = convert(words);
        sort(word.begin(), word.end());
        for (const auto& cnt : query) {
            bool flag = true;
            for (int i = word.size() - 1; i >= 0; i--) {
                if (word[i] <= cnt) {
                    ans.push_back(word.size() - i - 1);
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(word.size());
        }
        return ans;
    }
};

int main()
{
    return 0;
}
