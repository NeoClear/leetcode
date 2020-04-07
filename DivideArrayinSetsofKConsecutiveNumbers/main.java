import java.util.HashMap;
import java.util.TreeSet;

class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        HashMap<Integer, Integer> count = new HashMap<Integer, Integer>();
        TreeSet<Integer> keys = new TreeSet<>();
        for (int n : nums) {
            count.put(n, count.getOrDefault(n, 0) + 1);
            keys.add(n);
        }
        for (int n : keys) {
            if (count.getOrDefault(n, 0) == 0)
                continue;
            int minus = count.get(n);
            for (int i = n; i < n + k; i++) {
                if (count.getOrDefault(i, 0) < minus)
                    return false;
                count.put(i, count.get(i) - minus);
            }
        }
        return true;
    }
}