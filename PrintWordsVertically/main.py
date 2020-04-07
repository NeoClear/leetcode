from typing import List

class Solution:
    def printVertically(self, s: str) -> List[str]:
        words = list(s.split())
        m = 0
        for w in words:
            m = max(m, len(w))
        ret = []
        for i in range(len(words)):
            words[i] += (m - len(words[i])) * " "
        for i in range(m):
            ret.append("")
        for i in range(len(words)):
            for j in range(m):
                ret[j] += words[i][j]
        for i in range(len(ret)):
            ret[i] = ret[i].rstrip()
        return ret

ins = Solution()

for i in ins.printVertically("TO BE OR NOT TO BE"):
    print(i + "@")