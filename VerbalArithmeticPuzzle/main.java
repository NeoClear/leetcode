import java.util.HashMap;
import java.util.HashSet;

class Solution {
    HashSet<Character> left = new HashSet<>();
    Character right;
    boolean same = false;

    HashMap<Character, Integer> kv = new HashMap<>();
    HashMap<Character, Integer[]> use = new HashMap<>();
    Character[] attempt;

    int convert(final String w) {

    }

    public boolean isSolvable(final String[] words, final String result) {
        
        
        

        final int low = 0;
        for (final String word : words) {
            if (word.length() > result.length())
                return false;
            if (word.length() == result.length()) {
                left.add(word.toCharArray()[0]);
                same = true;
            }
            if (word.length() == result.length() - 1)
                low++;
            for (char ch : word.toCharArray())
                use.put(ch, {0, 9})
        }
    }
}