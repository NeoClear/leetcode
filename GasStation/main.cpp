#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, fuel = 0;
        int tag = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                tag = i + 1;
                fuel += tank;
                tank = 0;
            }
        }
        return fuel + tank >= 0 ? tag : -1;
    }
};

int main()
{
    return 0;
}
