import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        HashMap<String, Integer> count = new HashMap<>();
        for (int i = 0; i < s.length() - minSize + 1; i++) {
            String w = s.substring(i, i + minSize);
            HashSet<Character> cnt = new HashSet<Character>();
            for (char c : w.toCharArray())
                cnt.add(c);
            if (cnt.size() > maxLetters)
                continue;
            count.put(w, count.getOrDefault(w, 0) + 1);
        }
        int mm = 0;
        for (int i : count.values())
            mm = Math.max(mm, i);
        return mm;
    }
}