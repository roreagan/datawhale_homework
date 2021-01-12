class Solution:
    def longestPalindrome(self, s: str) -> str:
        count = len(s)
        if count == 0 or count == 1:
            return s
        longestPalindromelen = 1
        longestPalindromeStr = s[0:1]
        dp = [[False] * count for i in range(count)]
        for r in range(1, count):
            for l in range(0, r):
                if s[r] == s[l] and (r - l <= 2 or dp[l + 1][r - 1] == True):
                    dp[l][r] = True
                    if longestPalindromelen < r - l + 1:
                        longestPalindromelen = r - l + 1
                        longestPalindromeStr = s[l:l + longestPalindromelen]
        return longestPalindromeStr
