class Solution {
    public boolean is_even(int n) {
        int cnt = 0;
        for (; n != 0; n /= 10, cnt++) {}
        return cnt % 2 == 0;
    }
    public int findNumbers(int[] nums) {
        int cnt = 0;
        for (int n : nums)
            if (is_even(n))
                cnt++;
        return cnt;
    }
}