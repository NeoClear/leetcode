#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int digits(int n) {
        int cnt = 0;
        while (n) {
            n /= 10;
            cnt++;
        }
        return cnt;
    }
    int gen_seq(int d) {
        int ans = 0;
        for (int i = 1; i <= d; i++) {
            ans = ans * 10 + i;
        }
        return ans;
    }
    int gen_ones(int d) {
        int ans = 0;
        while (d--) {
            ans = ans * 10 + 1;
        }
        return ans;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int d = digits(low); d <= digits(high); d++) {
            for (int seq = gen_seq(d); seq <= high && digits(seq) == d; seq += gen_ones(d)) {
                if (seq >= low)
                    ans.push_back(seq);
                if (seq % 10 == 9)
                    break;
            }
        }
        return ans;
    }
};

int main() {
    Solution ins;
    for (const auto& it : ins.sequentialDigits(1000, 13000))
        cout << it << endl;
    return 0;
}