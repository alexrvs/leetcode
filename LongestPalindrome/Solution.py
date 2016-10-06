class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = [ 0 ] * 52
        l = len(s)
        for i in range(l):
            if ord(s[i]) >= ord('a') and ord(s[i]) <= ord('z'):
                cnt[ord(s[i]) - ord('a')] += 1
            elif ord(s[i]) >= ord('A') and ord(s[i]) <= ord('Z'):
                cnt[ord(s[i]) - ord('A') + 26] += 1
                
        max = 0;
        hasEven = 0;
        for i in range(0, 52):
            if cnt[i] % 2 != 0:
                hasEven = 1;
            max += (cnt[i] // 2) * 2;
            
        return max + hasEven;