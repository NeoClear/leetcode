#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int N = citations.size();
        int id;
        for (id = 0; id < N; id++) {
            if ((id == 0 || citations[N - id] >= id) &&
                    citations[N - id - 1] <= id)
                return id;
        }
        return id;
    }
};

int main()
{
    return 0;
}
