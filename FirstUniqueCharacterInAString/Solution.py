class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = len(s)
        cnt = [ 0 ] * 26
        for i in range(0, l):
            cnt[ord(s[i]) - ord('a')] += 1
        for i in range(0, l):
            if cnt[ord(s[i]) - ord('a')] == 1:
                return i
        return -1
