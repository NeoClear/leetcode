#include <bits/stdc++.h>

using namespace std;

struct seg {
    int left;
    int right;
    int val;
};

class NumArray {
public:
    vector<seg> tree;
    void buildGraph(int id, int i, int j, vector<int>& nums) {
        tree[id].left = i;
        tree[id].right = j;
        if (i == j) {
            tree[id].val = nums[i - 1];
            return;
        }
        int mid = (i + j) / 2;
        buildGraph(id * 2, i, mid, nums);
        buildGraph(id * 2 + 1, mid + 1, j, nums);
        tree[id].val = tree[id * 2].val + tree[id * 2 + 1].val;
    }
    void updateGraph(int id, int i, int u_) {
        if (tree[id].left == tree[id].right) {
            tree[id].val = u_;
            return;
        }
        int mid = (tree[id].left + tree[id].right) / 2;
        if (i <= mid)
            updateGraph(id * 2, i, u_);
        else
            updateGraph(id * 2 + 1, i, u_);
        tree[id].val = tree[id * 2].val + tree[id * 2 + 1].val;
    }
    int sumGraph(int id, int i, int j) {
        if (tree[id].left == i && tree[id].right == j)
            return tree[id].val;
        int mid = (tree[id].left + tree[id].right) / 2;
        if (j <= mid)
            return sumGraph(id * 2, i, j);
        else if (i > mid)
            return sumGraph(id * 2 + 1, i, j);
        else
            return sumGraph(id * 2, i, mid) + sumGraph(id * 2 + 1, mid + 1, j);
    }
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        int N = nums.size();
        tree = vector<seg>(N * 9);
        buildGraph(1, 1, N, nums);
    }

    void update(int i, int val) {
        updateGraph(1, i + 1, val);
    }

    int sumRange(int i, int j) {
        return sumGraph(1, i + 1, j + 1);
    }
};

int main()
{
    vector<int> in = {
        0, 9, 5, 7, 3
    };
    NumArray ins(in);
    cout<< ins.sumRange(4, 4)<< endl;
    cout<< ins.sumRange(2, 4)<< endl;
    return 0;
}
