#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = static_cast<int>(nums1.size()), l2 = static_cast<int>(nums2.size());
        int total = l1 + l2;
        int times = (total + 1) / 2;
        int ll1 = 0, ll2 = 0;
        double ans;
        for (int i = 0; i < times; i++) {
            if (ll1 >= l1) {
                ans = nums2[ll2];
                ll2++;
            } else if (ll2 >= l2) {
                ans = nums1[ll1];
                ll1++;
            } else {
                if (nums1[ll1] < nums2[ll2]) {
                    ans = nums1[ll1];
                    ll1++;
                } else {
                    ans = nums2[ll2];
                    ll2++;
                }
            }
        }
        if (total % 2 == 0) {
            double ppt = 0;
            if (ll1 >= l1)
                ppt = nums2[ll2];
            else if (ll2 >= l2)
                ppt = nums1[ll1];
            else {
                ppt = nums1[ll1] < nums2[ll2] ? nums1[ll1] : nums2[ll2];
            }
            ans = (ans + ppt) / 2;
        }
        return ans;

    }
};

int main()
{
    Solution ins;
    vector<int> q1 = {1, 2, 3};
    vector<int> q2 = {2};
    cout<< ins.findMedianSortedArrays(q1, q2)<< endl;
    return 0;
}
