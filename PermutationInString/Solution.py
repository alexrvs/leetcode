class Solution(object):
    def compareCharNums(self, charNums1, charNums2):
        for i in range(0, 26):
            if charNums1[i] != charNums2[i]:
                return False
        return True
    
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        s1Len = len(s1)
        s2Len = len(s2)
        if s1Len > s2Len:
            return False
        s1Nums = [ 0 ] * 26
        s2Nums = [ 0 ] * 26
        for i in range(0, s2Len):
            if i < s1Len:
                s1Nums[ord(s1[i]) - ord('a')] += 1
            s2Nums[ord(s2[i]) - ord('a')] += 1
            if i >= s1Len:
                s2Nums[ord(s2[i - s1Len]) - ord('a')] -= 1
            if i >= s1Len - 1:
                if True == self.compareCharNums(s1Nums, s2Nums):
                    return True
        return False