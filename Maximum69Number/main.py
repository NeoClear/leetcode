class Solution:
    def maximum69Number (self, num: int) -> int:
        s = str(num)
        ans = ""
        flag = True
        for c in s:
            if c == "6" and flag:
                flag = False
                ans += "9"
            else:
                ans += c
        return int(ans)
