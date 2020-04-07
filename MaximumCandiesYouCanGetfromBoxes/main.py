from typing import List
from collections import Counter
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        cnt = 0
        size = len(status)
        key = [0] * size
        visiting = Counter(initialBoxes)
        visited = Counter()
        changed = True
        while changed:
            changed = False
            remove = []
            insert = []
            for box in visiting:
                if status[box] == 1 or key[box] == 1:
                    changed = True
                    cnt += candies[box]
                    remove.append(box)
                    visited[box] = 1
                    for dest in containedBoxes[box]:
                        if dest not in visited:
                            insert.append(dest)
                    for k in keys[box]:
                        key[k] = 1
            for b in remove:
                del visiting[b]
            for b in insert:
                visiting[b] = 1
        return cnt

status = [1,1,1]
candies = [100,1,100]
keys = [[],[0,2],[]]
containedBoxes = [[],[],[]]
initialBoxes = [1]

ins = Solution()
print(ins.maxCandies(status, candies, keys, containedBoxes, initialBoxes))
