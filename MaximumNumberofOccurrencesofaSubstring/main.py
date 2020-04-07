from typing import List
import collections
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        cnt = {}
        for b in range(len(s) - minSize + 1):
            w = s[b: b + minSize]
            if len(collections.Counter(w)) > maxLetters:
                continue
            if w not in cnt:
                cnt[w] = 0
            cnt[w] += 1
        return max(cnt.values()) if len(cnt) != 0 else 0