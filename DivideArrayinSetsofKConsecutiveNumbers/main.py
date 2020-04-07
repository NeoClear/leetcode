from typing import List
from collections import Counter
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        cnt = Counter(nums)
        keys = sorted(cnt.keys())
        for n in keys:
            if cnt[n] > 0:
                minus = cnt[n]
                for i in range(n, n + k):
                    if cnt[i] < minus:
                        return False
                    cnt[i] -= minus
        return True


ins = Solution()
print(ins.isPossibleDivide([1, 2, 3, 3, 4, 4, 5, 6], 4))