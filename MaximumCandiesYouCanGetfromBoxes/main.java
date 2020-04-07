import java.util.Arrays;
import java.util.HashSet;

class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        int cnt = 0;
        HashSet<Integer> hasKey = new HashSet<>();
        HashSet<Integer> visiting = new HashSet<>();
        HashSet<Integer> visited = new HashSet<>();
        // Initialize visiting
        for (int i : initialBoxes)
            visiting.add(i);
        boolean changed = true;
        while (changed) {
            changed = false;
            HashSet<Integer> insert = new HashSet<>();
            HashSet<Integer> remove = new HashSet<>();
            for (int box : visiting) {
                if (status[box] == 1 || hasKey.contains(box)) {
                    cnt += candies[box];
                    changed = true;
                    visited.add(box);
                    remove.add(box);
                    for (int dest : containedBoxes[box])
                        insert.add(dest);
                    for (int k : keys[box])
                        hasKey.add((k));
                }
            }
            for (int it : remove)
                visiting.remove(it);
            for (int it : insert)
                if (!visited.contains(it))
                    visiting.add(it);
        }
        return cnt;
    }
}