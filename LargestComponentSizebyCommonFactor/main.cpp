#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> par;
    vector<int> child;
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    void merge(int a, int b) {
        child[find(a)] += child[find(b)];
        par[find(b)] = find(a);
    }
    int largestComponentSize(vector<int>& A) {
        int N = A.size();
        par = vector<int>(N);
        child = vector<int>(N, 1);
        for (int i = 0; i < N; i++)
            par[i] = i;
//        for (int i = 0 ; i < N; i++) {
//            for (int j = i + 1; j < N; j++)
//                if (gcd(A[i], A[j]) > 1 && find(i) != find(j))
//                    merge(i, j);
//        }
        for (int i = 0 ; i < N; i++) {
            for (int j = i + 1; j < N; j++)
                if (find(i) != find(j) && gcd(A[i], A[j]) > 1)
                    merge(i, j);
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
            ans = child[i] > ans ? child[i] : ans;
        return ans;
    }
};

int main()
{
    Solution ins;
    vector<int> in = {2,3,6,7,4,12,21,39};
    cout<< ins.largestComponentSize(in)<< endl;
    return 0;
}
