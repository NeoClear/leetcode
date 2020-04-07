from typing import List
class Solution:
    def is_even(self, num: int) -> bool:
        num = abs(num)
        cnt = 0
        while num != 0:
            num //= 10
            cnt += 1
        return cnt % 2 == 0

    def findNumbers(self, nums: List[int]) -> int:
        cnt = 0
        for it in nums:
            if self.is_even(it):
                cnt += 1
        return cnt


ins = Solution()
print(ins.findNumbers([1, 23, 432, 234, 5423, 245]))
