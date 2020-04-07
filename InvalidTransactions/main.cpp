#include <bits/stdc++.h>

using namespace std;

struct Transaction {
    string name;
    int time;
    int amout;
    string city;
};

class Solution {
public:
    Transaction decode(string s) {
        s.push_back(',');
        string cur;
        vector<string> temp;
        for (const auto& c : s) {
            if (c == ',') {
                temp.push_back(cur);
                cur.clear();
            } else
                cur.push_back(c);
        }
        Transaction ret;
        ret.name = temp[0];
        ret.time = stoi(temp[1]);
        ret.amout = stoi(temp[2]);
        ret.city = temp[3];
        return ret;
    }
    vector<string> ans;
    unordered_map<string, vector<Transaction>> map_;
    string toS(Transaction t) {
        return t.name + "," + to_string(t.time) + "," +
                to_string(t.amout) + "," + t.city;
    }
    void figure(vector<Transaction>& trans) {
        sort(trans.begin(), trans.end(), [](const Transaction& a, const Transaction& b){
            return a.time < b.time;
        });
        int n = trans.size();
        vector<int> cnt = vector<int>(trans.size(), 0);
        for (int i = 0; i < n; i++) {
            if (trans[i].amout > 1000 && !cnt[i]) {
                ans.push_back(toS(trans[i]));
                cnt[i] = 1;
            }
            for (int j = i + 1; j < n; j++) {
                if (trans[j].time - trans[i].time > 60)
                    break;
                if (trans[j].city != trans[i].city) {
                    if (!cnt[i]) {
                        ans.push_back(toS(trans[i]));
                        cnt[i] = 1;
                    }
                    if (!cnt[j]) {
                        ans.push_back(toS(trans[j]));
                        cnt[j] = 1;
                    }
                }
            }
        }
    }
    void solve() {
        for (auto it : map_) {
            auto trans = it.second;
            figure(trans);
        }
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        for (const auto& trans : transactions) {
            auto cur = decode(trans);
            map_[cur.name].push_back(cur);
        }
        solve();
        return ans;
    }
};

int main()
{
    Solution ins;
    vector<string> in = {
        "alice,20,800,mtv","alice,50,100,beijing"
    };
    for (const auto& it : ins.invalidTransactions(in))
        cout<< it<< endl;
    return 0;
}
