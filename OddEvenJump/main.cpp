#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> pos_(n, vector<int>(2));
        pos_[n - 1][0] = pos_[n - 1][1] = 1;
        map<int, int> bst;
        bst[A[n - 1]] = n - 1;
        int ans = 1;
        for (int i = n - 2; i >= 0; i--) {
            auto o = bst.lower_bound(A[i]);
            if (o != bst.end())
                pos_[i][0] = pos_[o->second][1];
            auto e = bst.upper_bound(A[i]);

            if (o != bst.begin())
                pos_[i][1] = pos_[prev(o)->second][0];
            if (pos_[i][0])
                ans++;
            bst[A[i]] = i;
        }
        return ans;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
