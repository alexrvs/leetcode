class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        nums = [ 0 ] * 26
        l = len(magazine)
        for i in range(0, l):
            nums[ord(magazine[i]) - ord('a')] += 1
        l = len(ransomNote)
        for i in range(0, l):
            idx = ord(ransomNote[i]) - ord('a')
            nums[idx] -= 1
            if nums[idx] < 0:
                return False
        return True
