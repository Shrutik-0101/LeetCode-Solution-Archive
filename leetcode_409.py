# ✨✨✨✨✨✨✨✨✨
# Credits: https://leetcode.com/u/naman_malik/
# ✨✨✨✨✨✨✨✨✨

# Process
# The method calculates the longest palindrome that can be built from the given string s.
# It uses the Counter class to count character frequencies.
# It sums up the largest even contributions from the character frequencies.
# If there is any character with an odd frequency, it adds one to the result to account for placing one odd character in the center of the palindrome.

# Solution
class Solution:
    def longestPalindrome(self, s: str) -> int:
        from collections import Counter
        m = Counter(s)
        cnt = 0
        one = 0
        for freq in m.values():
            if freq>1:
                cnt += (freq//2) * 2
            if freq % 2 == 1:
                one = 1
        return cnt + one