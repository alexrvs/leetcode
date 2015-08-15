class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLongestSubstring(self, s):
        start = 0
        length = 0
        max = 0
        i = 0
        s_len = len(s)
        if s_len == 0:
            return 0
        for i in list(range(1, s_len)):
            for j in list(range(start, i)):
                if s[j] == s[i]:
                    length = i - start;
                    if max < length:
                        max = length
                    start = j+1
                    break;

        length = s_len - start
        if max < length:
            max = length
        return max
